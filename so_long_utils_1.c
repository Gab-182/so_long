/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:42:11 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 11:20:39 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*=======================================================================*/
void	error(int i, char *buffer)
{
	if (i == 1)
		ft_printf("Error: Maps is not valid\n");
	else if (i == 2)
		ft_printf("Error: Maps is not valid\n");
	else if (i == 3)
		ft_printf("Error: Maps is not valid\n");
	else if (i == 4)
		ft_printf("Error: Maps is not valid\n");
	else if (i == 10)
		ft_printf("Error: Maps is not valid(at least one coine 'C')\n");
	else
		ft_printf("Error: Maps is not valid\n");
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	exit(EXIT_FAILURE);
}

/*=======================================================================*/
void	extension_error(void)
{
	ft_printf("\nWrong file extension!!!!!\n");
	ft_printf("We accept just (.ber) extension\n");
	exit(EXIT_FAILURE);
}

/*=======================================================================*/