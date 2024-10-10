/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:02:08 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/05 03:29:41 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_exit(t_game *game)
{
	clean_exit(game, NULL);
	return (0);
}

void	clean_exit(t_game *game, const char *message)
{
	if (game->map)
		free_map(game);
	if (game->map_copy)
		free_map_copy(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	clean_exit2_destroy_img(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (message)
		ft_printf("Error\n%s\n", message);
	exit(1);
}

void	clean_exit2_destroy_img(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_collectible)
			mlx_destroy_image(game->mlx, game->img_collectible);
		if (game->img_empty)
			mlx_destroy_image(game->mlx, game->img_empty);
		if (game->img_player_up)
			mlx_destroy_image(game->mlx, game->img_player_up);
		if (game->img_player_right)
			mlx_destroy_image(game->mlx, game->img_player_right);
		if (game->img_player_down)
			mlx_destroy_image(game->mlx, game->img_player_down);
		if (game->img_player_left)
			mlx_destroy_image(game->mlx, game->img_player_left);
		if (game->img_exit_close)
			mlx_destroy_image(game->mlx, game->img_exit_close);
		if (game->img_exit_open)
			mlx_destroy_image(game->mlx, game->img_exit_open);
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = -1;
		while (++i < game->count_lines)
			free(game->map[i]);
		free(game->map);
	}
}

void	free_map_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free (game->map_copy);
}
