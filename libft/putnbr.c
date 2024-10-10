/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:42:01 by jd-halle          #+#    #+#             */
/*   Updated: 2024/06/13 18:22:10 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putnbr_u(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_xx(unsigned long long int n, char type)
{
	char	*base;
	int		count;

	count = 0;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_putnbr_xx(n / 16, type);
		count += ft_putnbr_xx(n % 16, type);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}

int	ft_putadress_p(unsigned long long int n)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	if (n == 0)
	{
		count += ft_putstr ("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_xx(n, x);
	return (count);
}
