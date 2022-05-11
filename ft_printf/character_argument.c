/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:56:58 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:42:39 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character_argument(va_list args)
{
	int		c;
	int		len;

	len = 0;
	c = va_arg(args, int);
	len = ft_putchar(c);
	return (len);
}
