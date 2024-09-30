/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 04:13:39 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:53:32 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *FILE, t_game *game)
{
	int	len;

	len = ft_strlen(FILE);
	if (len < 4 || ft_strcmp(FILE + len - 4, ".ber") != 0)
		clean_exit(game, "Le nom du fichier ne contient pas .ber");
}

void	count_lines(char *FILE, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(FILE, O_RDONLY);
	if (fd == -1)
		clean_exit (game, "Impossible d'ouvrir la map\n");
	line = get_next_line(fd);
	while (line)
	{
		game->count_lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (game->count_lines <= 0)
		clean_exit(game, "Pas de lignes dans le fichier de la carte\n");
	close (fd);
}

void	fill_map(char *FILE, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(FILE, O_RDONLY);
	if (fd == -1)
		clean_exit (game, "Impossible d'ouvrir la map\n");
	game->i = 0;
	while (game->i < game->count_lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		game->map[game->i] = ft_strdup(line);
		free(line);
		game->i++;
	}
	game->map[game->i] = NULL;
	close (fd);
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->count_lines)
	{
		ft_printf("%s", game->map[i]);
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->count_p += 1;
			if (game->map[i][j] == 'E')
				game->count_e += 1;
			if (game->map[i][j] == 'C')
				game->count_c += 1;
			if (game->map[i][j] == '0' || game->map[i][j] == '1'
				|| game->map[i][j] == 'P'
				|| game->map[i][j] == 'C' || game->map[i][j] == 'E'
				|| game->map[i][j] == '\n')
				j++;
			else
				clean_exit(game, "Il y a un ou plusieurs caracteres invalides");
		}
	}
}

void	check_map2(t_game *game)
{
	if (game->count_c <= 0)
		clean_exit(game, "Il n'y a aucun collectible C\n");
	if (game->count_p != 1)
		clean_exit(game, "Nombre de players P different de 1\n");
	if (game->count_e != 1)
		clean_exit(game, "Nombre de sorties E different de 1\n");
	game->line_length = check_lines(game) -1;
	printf("line_len = %d\n", game->line_length);
	check_1st_and_last_line(game);
	check_delimitation_map(game);
}
