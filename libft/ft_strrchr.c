/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:55:01 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:19:02 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	unsigned int	i;

	i = ft_strlen(str);
	if (c == 0)
	{
		while (str[i] != 0)
			i--;
		return ((char *)str + i);
	}
	while (i > 0)
	{
		i--;
		if (str[i] == c)
			return ((char *)str + i);
	}
	return (NULL);
}
