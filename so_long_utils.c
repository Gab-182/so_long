/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:42:11 by gabdoush          #+#    #+#             */
/*   Updated: 2022/01/30 13:45:16 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*------------------------------------------------------------*/
void	error(int i, char *buffer)
{
	if (i == 1)
		printf("Error: Maps is not valid(not rectangle )\n");
	else if (i == 2)
		printf("Error: Maps is not valid(top wall)\n");
	else if (i == 3)
		printf("Error: Maps is not valid(middle wall)\n");
	else if (i == 4)
		printf("Error: Maps is not valid(bottom wall)\n");
	else
		printf("Error: Maps is not valid\n");
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------*/
void	ft_putchar(int c)
{
	write(1, &c, 1);
}

/*------------------------------------------------------------*/
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

/*------------------------------------------------------------*/
void	ft_putnbr(int n)
{
	int		len;

	len = 0;
	if (n <= 2147483647 && n >= -2147483648)
	{
		if (n < 0)
		{
			if (n == -2147483648)
				return (ft_putstr("-2147483648"));
			ft_putchar('-');
			n = n * -1;
		}
		if (n <= 9)
			ft_putchar(n + '0');
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}
