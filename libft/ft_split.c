/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:58:06 by jd-halle          #+#    #+#             */
/*   Updated: 2024/05/22 20:08:51 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count(str, c) + 1));
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
			tab[i++] = ft_substr(str, 0, len);
			str = str + len;
		}
	}
	tab[i] = NULL;
	return (tab);
}
