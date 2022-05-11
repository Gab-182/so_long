/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_x_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:57:25 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:01 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_x_argument(va_list args)
{
	int		num;
	int		len;

	len = 0;
	num = va_arg(args, int);
	len = ft_putnbr_x(num);
	return (len);
}
