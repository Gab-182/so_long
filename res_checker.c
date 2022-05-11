/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:03:04 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/06 17:23:50 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_checker(t_base *base)
{
	size_t	i;
	int		e_counter;

	i = 0;
	e_counter = 0;
	while (base->map[i] != '\0')
	{
		if (base->map[i] == 'E')
			e_counter++;
		i++;
	}
	if (e_counter != 1)
	{
		ft_printf("Error, Should be one Exit...\n");
		exit(EXIT_FAILURE);
	}
}

/*-----------------------------------------------------------------------*/
void	position_checker(t_base *base)
{
	int	i;
	int	p_counter;

	i = 0;
	p_counter = 0;
	while (base->map[i] != '\0')
	{
		if (base->map[i] == 'P')
			p_counter++;
		i++;
	}
	if (p_counter != 1)
	{
		ft_printf("Error, Should be one Character...\n");
		exit(EXIT_FAILURE);
	}
}

/*-----------------------------------------------------------------------*/
void	coin_checker(t_base *base)
{
	int	i;

	i = 0;
	while (base->map[i] != '\0')
	{
		if (base->map[i] != 'C')
			i++;
		if (i >= (int)ft_strlen(base->map))
			error(10, base->map);
		if (base->map[i] == 'C')
			break ;
	}
}

/*-----------------------------------------------------------------------*/