/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:02:22 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/02 22:02:00 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_lines(t_game *game)
{
	int	i;
	int	len2;

	i = 1;
	game->len_line = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		len2 = ft_strlen(game->map[i]);
		if (game->len_line != len2)
			clean_exit(game, "On a des lignes de differentes tailles\n");
		i++;
	}
}

void	check_1st_and_last_line(t_game *game)
{
	int	j;

	j = 0;
	while (j < ft_strlen(game->map[0]) - 1)
	{
		if (game->map[0][j] != '1')
			clean_exit(game, "1ere ligne ne contient pas que des 1\n");
		if (game->map[game->count_lines - 1][j] != '1')
			clean_exit(game, "Derniere ligne ne contient pas que des 1\n");
		j++;
	}
}

void	check_delimitation_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_lines)
	{
		if (game->map[i][0] != '1')
			clean_exit(game, "Une ligne ne commence pas par 1\n");
		if (game->map[i][game->len_line -2] != '1')
			clean_exit(game, "Une ligne ne finit pas par 1\n");
		i++;
	}
}
