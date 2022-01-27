/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:21:58 by gabdoush          #+#    #+#             */
/*   Updated: 2022/01/27 18:21:59 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 1)
		ft_putstr("Error: Maps is not valid (increase the raws number)\n");
	else if (i == 2)
		ft_putstr("Error: Maps is not valid(top border contains gaps)\n");
	else if (i == 3)
		ft_putstr("Error: Maps is not valid(bottom border contains gaps)\n");
	else if (i == 4)
		ft_putstr("Error: Maps is not valid(side border contains gaps)\n");
	exit(EXIT_FAILURE);
}
