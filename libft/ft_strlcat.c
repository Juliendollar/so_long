/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:03:16 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:17:33 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char *src, int n)
{
	int	i;
	int	j;
	int	total_len;

	total_len = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	j = 0;
	while (i < n && dest[i])
		i++;
	while (src[j] && i + j + 1 < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < n)
		dest[i + j] = 0;
	if (n < ft_strlen(dest))
		total_len = n + ft_strlen(src);
	return (total_len);
}
