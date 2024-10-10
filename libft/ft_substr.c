/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:01:43 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:18:20 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, unsigned int start, size_t n)
{
	char	*str2;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len)
		return (ft_strdup(""));
	len = len - start;
	if (len > n)
		len = n;
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (0);
	ft_strlcpy(str2, str + start, n + 1);
	return (str2);
}
