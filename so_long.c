/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:28:11 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/10 16:26:29 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc == 2)
	{
		check_extension(argv[1], &game);
		count_lines(argv[1], &game);
		game.map = malloc(sizeof(char *) * (game.count_lines +1));
		if (!game.map)
			clean_exit(&game, "Erreur d'allocation mémoire pour la carte\n");
		fill_map(argv[1], &game);
		check_map(&game);
		check_map2(&game);
		check_valid_path(&game, &game.player);
		mlx(&game);
	}
	else
		ft_printf("Error\nNombre d'arguments differents de 1");
	return (0);
}

int	new_pos_valid(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_y = game->player.y + y;
	new_x = game->player.x + x;
	if (new_x < 0 || new_y < 0 || new_y >= game->count_lines
		|| new_x >= (int)ft_strlen(game->map[new_y]))
		return (0);
	next_tile = game->map[game->player.y + y][game->player.x + x];
	if (next_tile == '0' || next_tile == 'C' || next_tile == 'E')
		return (1);
	else
		return (0);
}

void	move_player(t_game *game, int x, int y)
{
	char	next_tile;

	if (new_pos_valid(game, x, y))
	{
		next_tile = game->map[game->player.y + y][game->player.x + x];
		if (next_tile == 'E' && game->count_c > 0)
			return ;
		game->move_count++;
		printf("count = %d\n", game->move_count);
		game->map[game->player.y][game->player.x] = '0';
		game->player.y = game->player.y + y;
		game->player.x = game->player.x + x;
		if (next_tile == 'C')
		{
			game->map[game->player.y][game->player.x] = '0';
			game->count_c--;
		}
		else if (next_tile == 'E')
			clean_exit(game, NULL);
		render_game(game);
	}
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		clean_exit(game, NULL);
	else if (keycode == UP_W)
	{
		game->player.direction = 0;
		move_player(game, 0, -1);
	}
	else if (keycode == RIGHT_D)
	{
		game->player.direction = 1;
		move_player(game, 1, 0);
	}
	else if (keycode == DOWN_S)
	{
		game->player.direction = 2;
		move_player(game, 0, 1);
	}
	else if (keycode == LEFT_A)
	{
		game->player.direction = 3;
		move_player(game, -1, 0);
	}
	return (0);
}

void	*get_image_for_tile(t_game *game, char tile, int player_direction)
{
	if (tile == '1')
		return (game->img_wall);
	else if (tile == 'C')
		return (game->img_collectible);
	else if (tile == 'E')
	{
		if (game->count_c != 0)
			return (game->img_exit_close);
		if (game->count_c == 0)
			return (game->img_exit_open);
	}
	else if (tile == 'P')
	{
		if (player_direction == 0)
			return (game->img_player_up);
		else if (player_direction == 1)
			return (game->img_player_right);
		else if (player_direction == 2)
			return (game->img_player_down);
		else if (player_direction == 3)
			return (game->img_player_left);
	}
	else if (tile == '0')
		return (game->img_empty);
	return (NULL);
}
