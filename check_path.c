/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:09:49 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/10 15:53:36 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position_player(t_game *game, t_player *player)
{
	player->y = 0;
	while (game->map[player->y])
	{
		player->x = 0;
		while (game->map[player->y][player->x])
		{
			if (game->map[player->y][player->x] == 'P')
				return ;
			player->x++;
		}
		player->y++;
	}
}

void	check_valid_path(t_game *game, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	game->map_copy = create_map_copy(game, player);
	flood_fill(game->map_copy, player->y, player->x, game);
	while (++i < game->count_lines)
	{
		j = 0;
		while (j < game->len_line)
		{
			if (game->map[i][j] == 'C')
			{
				if (game->map_copy[i][j] != 'V')
					clean_exit(game, "collectible non accessible");
			}
			if (!game->flag)
				clean_exit(game, "exit non accessible");
			j++;
		}
	}
}

void	flood_fill(char **map_copy, int i, int j, t_game *game)
{
	if (map_copy[i][j] == 'E')
		game->flag = 1;
	if (map_copy[i][j] == '1' || map_copy[i][j] == 'V' || map_copy[i][j] == 'E')
		return ;
	map_copy[i][j] = 'V';
	flood_fill(map_copy, i +1, j, game);
	flood_fill(map_copy, i -1, j, game);
	flood_fill(map_copy, i, j +1, game);
	flood_fill(map_copy, i, j -1, game);
}

char	**create_map_copy(t_game *game, t_player *player)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (game->count_lines +1));
	if (!map_copy)
	{
		ft_printf("Error\nErreur d'allocation memoire\n");
		return (NULL);
	}
	while (i < game->count_lines)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = 0;
	find_position_player(game, player);
	return (map_copy);
}

void	mlx(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->win, 17, 0, my_exit, game);
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_loop(game->mlx);
}
