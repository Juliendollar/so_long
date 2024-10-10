/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:28:47 by jd-halle          #+#    #+#             */
/*   Updated: 2024/05/22 14:06:35 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (c > 256)
	{
		c = c % 256;
	}
	while (str[i])
	{
		if (str[i] == c)
			return ((char *) str + i);
		i++;
	}
	if (c == 0 && str[i] == 0)
		return ((char *)str + i);
	return (0);
}
