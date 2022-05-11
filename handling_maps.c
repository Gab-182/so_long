/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:39:31 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/11 21:52:48 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Glopal variable */
int	g_x = 0;
int	g_y = 0;

int	g_index_chara = 0;
int	g_future_chara_index = 0;

/*============================================================================*/
void	just_drawing(t_base *base)
{
	int	i;

	i = 0;
	base->tok_count = 0;
	exit_checker(base);
	position_checker(base);
	coin_checker(base);
	while (base->map[i] != '\0')
	{
		if (base->map[i] == '1')
			map_wall(base);
		else if (base->map[i] == '\n')
			map_new_line();
		else if (base->map[i] == '0')
			map_floor(base);
		else if (base->map[i] == 'P')
			map_char(base, i);
		else if (base->map[i] == 'C')
			map_coins(base);
		else if (base->map[i] == 'E')
			map_exit(base);
		else
			error(6, base->map);
		i++;
	}
}

/*=======================================================================*/
int	handle_moving(int key, t_base *base)
{
	if (key == 0)
		key_a(base);
	if (key == 1)
		key_s(base);
	if (key == 2)
		key_d(base);
	if (key == 13)
		key_w(base);
	closing_esc(key, base);
	return (0);
}

/*=======================================================================*/
void	key_w(t_base *base)
{
	g_future_chara_index = g_index_chara - (line_length(base) + 1);
	if (check_walls(g_future_chara_index, base) == 0)
	{
		g_index_chara = g_future_chara_index;
		if (check_exit(g_index_chara, base) == 1)
		{
			if ((base->g_collected_coins) - 1 == base->tok_count)
				finishing();
		}
		mlx_destroy_image(base->mlx, base->xpm_img);
		base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, \
		&base->width, &base->height);
		mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, \
		base->g_x_chara, base->g_y_chara);
		base->g_y_chara -= 50;
		mlx_destroy_image(base->mlx, base->xpm_img);
		base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, \
		&base->width, &base->height);
		mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, \
		base->g_x_chara, base->g_y_chara);
		if (check_coins(g_index_chara, base) == 1)
			base->g_collected_coins++;
		base->g_moves++;
		print_moves(base);
	}
}

/*=======================================================================*/
void	map_new_line(void)
{
	g_y += 50;
	g_x = 0;
}

/*=======================================================================*/