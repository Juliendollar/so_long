/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:50:29 by jd-halle          #+#    #+#             */
/*   Updated: 2024/04/25 16:54:37 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *f, const char *a, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (a[i] == 0)
		return ((char *)f);
	while (f[i] && i < n)
	{
		j = 0;
		while (f[i + j] == a[j] && i + j < n)
			j++;
		if (a[j] == 0)
			return ((char *)&f[i]);
		i++;
	}
	return (0);
}
