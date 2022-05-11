/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_argument.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:40 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:27 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int_argument(va_list args)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(args, unsigned int);
	len += ft_putnbr_unsigned(u);
	return (len);
}
