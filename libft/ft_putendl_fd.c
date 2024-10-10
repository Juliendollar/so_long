/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:12:44 by jd-halle          #+#    #+#             */
/*   Updated: 2024/05/22 15:44:08 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	while (str && *str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
	if (str)
		ft_putchar_fd('\n', fd);
}
