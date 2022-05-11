/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:04:22 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 11:10:05 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char para)
{
	if (para == 'd' || para == 'i' || para == 'u' || para == 'x'
		|| para == 'X' || para == 'p' || para == '%'
		|| para == 'c' || para == 's')
		return (0);
	else
		return (1);
}

int	after_percent(va_list args, char para_val)
{
	int		len;

	len = 0;
	if (para_val == '%')
		len = ft_putchar('%');
	else if (para_val == 'd' || para_val == 'i')
		len = integer_argument(args);
	else if (para_val == 'u')
		len = unsigned_int_argument(args);
	else if (para_val == 'c')
		len = character_argument(args);
	else if (para_val == 's')
		len = string_argument(args);
	else if (para_val == 'x')
		len = hex_x_argument(args);
	else if (para_val == 'X')
		len = hex_upper_argument(args);
	else if (para_val == 'p')
		len = pointer_argument(args);
	return (len);
}

int	ft_printf(const char *para, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start (args, para);
	while (*para != '\0')
	{	
		if (*para == '%')
		{
			para++;
			if (is_flag(*para) == 0)
				len += after_percent(args, *para);
			else
				len += ft_putchar(*para);
		}
		else
			len += ft_putchar(*para);
		para++;
	}
	va_end(args);
	return (len);
}
