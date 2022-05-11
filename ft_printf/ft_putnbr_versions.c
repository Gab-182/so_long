/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_versions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:28:58 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:33:05 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;

	len = 0;
	if (n <= 2147483647 && n >= -2147483648)
	{
		if (n < 0)
		{
			if (n == -2147483648)
				return (len = ft_putstr("-2147483648"));
			len += ft_putchar('-');
			n = n * -1;
		}
		if (n <= 9)
			len += ft_putchar(n + '0');
		if (n > 9)
		{
			len += ft_putnbr(n / 10);
			len += ft_putnbr(n % 10);
		}
	}
	return (len);
}

int	ft_putnbr_x(unsigned int n)
{
	int		len;

	len = 0;
	if (n <= 9 && n >= 0)
		len += ft_putchar(n + '0');
	if (n > 15)
	{
		len += ft_putnbr_x(n / 16);
		len += ft_putnbr_x(n % 16);
	}
	if (n > 9 && n < 16)
	{
		len += ft_putchar(n + 87);
	}
	return (len);
}

int	ft_putnbr_x_upper(unsigned int n)
{
	int		len;

	len = 0;
	if (n <= 9 && n >= 0)
		len += ft_putchar(n + '0');
	if (n > 15)
	{
		len += ft_putnbr_x_upper(n / 16);
		len += ft_putnbr_x_upper(n % 16);
	}
	if (n > 9 && n < 16)
	{
		len += ft_putchar(n + 55);
	}
	return (len);
}

int	ft_putnbr_p(unsigned long long int n)
{
	int		len;

	len = 0;
	if (n <= 9 && n >= 0)
		len += ft_putchar(n + '0');
	if (n > 15)
	{
		len += ft_putnbr_p(n / 16);
		len += ft_putnbr_p(n % 16);
	}
	if (n > 9 && n < 16)
	{
		len += ft_putchar(n + 87);
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else if (n < 10)
	{
		len += ft_putchar((char)(n + '0'));
	}
	return (len);
}
