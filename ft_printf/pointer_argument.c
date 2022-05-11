/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:56 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:13 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_argument(va_list args)
{
	int							len;
	unsigned long long int		pointer;

	len = 0;
	pointer = va_arg(args, unsigned long long int);
	len = ft_putstr("0x");
	len += ft_putnbr_p(pointer);
	return (len);
}
