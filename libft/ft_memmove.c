/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:57:16 by jd-halle          #+#    #+#             */
/*   Updated: 2024/05/04 01:44:14 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(unsigned char **destination, const unsigned char **source,
		void *dest, const void *src)
{
	*destination = (unsigned char *)dest;
	*source = (const unsigned char *)src;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	i = 0;
	init(&destination, &source, dest, src);
	if (dest == src)
		return (destination);
	if (dest < src)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			destination[n - 1] = source[n - 1];
			n--;
		}
	}
	return (destination);
}
