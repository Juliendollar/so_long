/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:54:19 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:19:48 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	if (!str1)
		len1 = 0;
	else
		len1 = ft_strlen(str1);
	if (!str2)
		len2 = 0;
	else
		len2 = ft_strlen(str2);
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str1, len1);
	ft_memcpy(dest + len1, str2, len2);
	dest[len1 + len2] = 0;
	return (dest);
}
