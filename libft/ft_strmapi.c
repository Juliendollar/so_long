/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:32 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/30 05:20:13 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *str, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = f(i, str[i]);
		i++;
	}
	return (new);
}
