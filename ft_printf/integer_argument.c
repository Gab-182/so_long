/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 03:47:56 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/23 03:51:02 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	integer_argument(va_list args)
{
	int		d;
	int		len;

	len = 0;
	d = va_arg(args, int);
	len = ft_putnbr(d);
	return (len);
}
