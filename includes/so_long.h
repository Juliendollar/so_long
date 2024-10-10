/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:50:12 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/10 16:26:10 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# define ESC_KEY 65307
# define WIDTH 1984   //1952 pour le 32*32
# define HEIGHT 1024 //960  //992   pour le 32*32
# define UP_W 119
# define DOWN_S 115
# define LEFT_A 97
# define RIGHT_D 100
# define IMG_HEIGHT 64
# define IMG_WIDTH 64
# define TILE_SIZE 64

typedef struct s_player
{
	int	x;
	int	y;
	int	direction;
}	t_player;
typedef struct s_game
{
	char		**map;
	char		**map_copy;
	char		**map_copy2;
	int			count_lines;
	int			count_p;
	int			count_e;
	int			count_c;
	int			i;
	int			j;
	int			len_line;
	void		*mlx;
	void		*win;
	int			bpp;
	int			endian;
	void		*img_player;
	void		*img_player_up;
	void		*img_player_down;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_collectible;
	void		*img_wall;
	void		*img_empty;
	void		*img_exit_close;
	void		*img_exit_open;
	int			start_x;
	int			start_y;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	int			offset_x;
	int			offset_y;
	void		*img2;
	void		*player_img;
	int			end_x;
	int			end_y;
	int			move_count;
	int			flag;
	t_player	player;
}	t_game;

int		key_handler(int keycode, t_game *game);

void	check_extension(char *file, t_game *game);
void	fill_map(char *file, t_game *game);
void	count_lines(char *FILE, t_game *game);
void	mlx(t_game *game);
void	check_map(t_game *game);
void	free_map(t_game *game);
void	check_map2(t_game *game);
void	check_lines(t_game *game);
void	check_1st_and_last_line(t_game *game);
void	check_delimitation_map(t_game *game);
void	check_valid_path(t_game *game, t_player *player);

void	find_position_player(t_game *game, t_player *player);
void	flood_fill(char **map_copy, int i, int j, t_game *game);
char	**create_map_copy(t_game *game, t_player *player);
void	free_map_copy(t_game *game);
void	clean_exit(t_game *game, const char *message);
int		my_exit(t_game *game);

int		new_pos_valid(t_game *game, int x, int y);
void	move_player(t_game *game, int x, int y);

void	render_game(t_game *game);
void	mlx_put_img(t_game *game);
void	*get_image_for_tile(t_game *game, char tile, int player_direction);
void	load_images(t_game *game);
void	init_mlx(t_game *game);
void	clean_exit2_destroy_img(t_game *game);

#endif
