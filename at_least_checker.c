/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_least_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:08:56 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 12:46:43 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_length(t_base *base)
{
	int	line_len;

	line_len = 0;
	while (base->map[line_len] != '\0' && base->map[line_len] != '\n')
		line_len++;
	return (line_len);
}

/*=======================================================================*/
int	check_walls(int future_chara_index, t_base *base)
{
	if (base->map[future_chara_index] == 'E'
		&& base->g_collected_coins - 1 != base->tok_count)
		return (1);
	if (base->map[future_chara_index] == '1')
		return (1);
	return (0);
}

/*=======================================================================*/
int	check_coins(int index_chara, t_base *base)
{
	if (base->map[index_chara] == 'C')
	{
		base->map[index_chara] = '0';
		return (1);
	}
	return (0);
}

/*=======================================================================*/
int	check_exit(int index_chara, t_base *base)
{
	if (base->map[index_chara] == 'E')
		return (1);
	return (0);
}

/*=======================================================================*/
void	col_raw(t_base *base)
{
	int	i;

	base->g_raw = 0;
	base->g_col = 0;
	i = 0;
	while (base->map[i] != '\0')
	{
		if (base->map[i] == '1')
			base->g_col += 1;
		else if (base->map[i] == '\n')
		{
			base->g_raw += 1;
			base->g_col = 0;
		}
		else if (base->map[i] == '0')
			base->g_col += 1;
		else if (base->map[i] == 'P')
			base->g_col += 1;
		else if (base->map[i] == 'C')
			base->g_col += 1;
		else if (base->map[i] == 'E')
			base->g_col += 1;
		i++;
	}
	base->g_raw += 1;
}

/*=======================================================================*/