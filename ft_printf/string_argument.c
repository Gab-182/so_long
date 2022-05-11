/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:55:44 by gabdoush          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:20 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_argument(va_list	args)
{
	int		len;
	char	*s;
	char	*str;

	len = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		str = "(null)";
		len += ft_putstr(str);
		return (len);
	}
	else
		len += ft_putstr(s);
	return (len);
}
