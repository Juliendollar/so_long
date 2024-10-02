/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:00:09 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/02 21:13:46 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	offset(t_game *game)
{
	game->offset_x = game->player.x * TILE_SIZE - (WIDTH / 2);
	game->offset_y = game->player.y * TILE_SIZE - (HEIGHT / 2);
	if (game->offset_x < 0)
	{
		game->offset_x = 0;
	}
	else if (game->offset_x > (game->len_line * TILE_SIZE - WIDTH))
	{
		game->offset_x = game->len_line * TILE_SIZE - WIDTH;
	}
	if (game->offset_y < 0)
	{
		game->offset_y = 0;
	}
	else if (game->offset_y > (game->count_lines * TILE_SIZE - HEIGHT))
	{
		game->offset_y = (game->count_lines) * TILE_SIZE - HEIGHT;
	}
	game->start_y = game->offset_y / TILE_SIZE;
	game->start_x = game->offset_x / TILE_SIZE;
	game->player_img = get_image_for_tile(game, 'P', game->player.direction);
	if (!game->player_img)
	{
		printf("Erreur: Impossible de charger l'image du joueur.\n");
	}
	game->y = game->start_y;
}

void	mlx_put_img(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		(game->player.x * TILE_SIZE - game->offset_x),
		(game->player.y * TILE_SIZE - game->offset_y));
}

void	render_game(t_game *game)
{
	int	prev_x = game->player.x;
	int	prev_y = game->player.y;
	offset(game);
	int	start_x = (game->offset_x / TILE_SIZE);
	int	start_y = (game->offset_y / TILE_SIZE);
	int	end_x = start_x + (WIDTH / TILE_SIZE);
	int	end_y = start_y + (HEIGHT / TILE_SIZE);
	if (start_x < 0) start_x = 0;
	if (start_y < 0) start_y = 0;
	if (end_x > game->len_line) end_x = game->len_line;
	if (end_y > game->count_lines) end_y = game->count_lines;
	for (int y = start_y; y < end_y; y++)
	{
		for (int x = start_x; x < end_x; x++)
		{
			game->img2 = get_image_for_tile(game, game->map[y][x], game->player.direction);
			if (game->img2)
			{
				if ((x != prev_x || y != prev_y) || (game->player.x == x && game->player.y == y))
				{
					mlx_put_image_to_window(game->mlx, game->win, game->img2, (x * TILE_SIZE - game->offset_x), (y * TILE_SIZE - game->offset_y));
				}
			}
		}
	}
	game->player_img = get_image_for_tile(game, 'P', game->player.direction);
	if (game->player_img)
	{
		mlx_put_img(game);
	}
}

void	load_images(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = IMG_WIDTH;
	img_h = IMG_HEIGHT;
	game->img_player_up = mlx_xpm_file_to_image(game->mlx, "assets/up.xpm",
			&img_w, &img_h);

	game->img_player_down = mlx_xpm_file_to_image(game->mlx, "assets/down.xpm",
			&img_w, &img_h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx, "assets/right.xpm",
			&img_w, &img_h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx, "assets/left.xpm",
			&img_w, &img_h);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm",
			&img_w, &img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&img_w, &img_h);
	game->img_collectible = mlx_xpm_file_to_image (game->mlx,
			"assets/collectible.xpm", &img_w, &img_h);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx, "assets/exit_close.xpm",
			&img_w, &img_h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, "assets/exit_open.xpm",
			&img_w, &img_h);
}

void	init_mlx(t_game *game)
{
	int	largeur_reel;

	largeur_reel = (game->len_line -1) * IMG_WIDTH;
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, "Erreur d'initialisation de mlx\n");
	if ((game->len_line -1) * IMG_WIDTH > IMG_WIDTH * 31)
		largeur_reel = IMG_WIDTH * 30;
	game->win = mlx_new_window(game->mlx, largeur_reel,
			game->count_lines * IMG_HEIGHT, "so_long");
	if (!game->win)
		clean_exit(game, "Erreur de création de la fenêtre\n");
	game->img = mlx_new_image(game->mlx, (game->len_line -1) * IMG_WIDTH,
			game->count_lines * IMG_HEIGHT);
	int temp_len_line = game->len_line;
	game->addr = mlx_get_data_addr(game->img, &game->bpp,
			&game->len_line, &game->endian);
	game->len_line = temp_len_line;
	load_images(game);
	render_game(game);
}
