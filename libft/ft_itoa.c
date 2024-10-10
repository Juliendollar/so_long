/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:02:49 by jd-halle          #+#    #+#             */
/*   Updated: 2024/04/25 19:13:22 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	count;

	count = 1;
	while (n)
	{
		n = n / 10;
		if (n)
			count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*dest;
	size_t		i;
	long int	num;

	num = n;
	i = ft_count(n);
	if (n < 0)
	{
		num = num * -1;
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i] = 0;
	while (i)
	{
		dest[i - 1] = num % 10 + 48;
		num = num / 10;
		i--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
