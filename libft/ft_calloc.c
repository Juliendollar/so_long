/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:33:51 by jd-halle          #+#    #+#             */
/*   Updated: 2024/05/22 14:18:35 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	char	*tmp;
	size_t	i;

	if ((nmemb >= 65535 && n >= 65535) || nmemb * n >= 65535)
	{
		return (NULL);
	}
	i = 0;
	tmp = malloc(nmemb * n);
	if (!tmp)
		return (0);
	while (i < nmemb * n)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
