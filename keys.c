/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:56:02 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/11 21:53:22 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

extern int	g_x;
extern int	g_y;

extern int	g_index_chara;
extern int	g_future_chara_index;

/*=======================================================================*/
int	closing_x(t_base *data)
{
	free(data->map);
	data->map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/*=======================================================================*/
void	closing_esc(int key, t_base *data)
{
	if (key == 53)
	{
		free(data->map);
		data->map = NULL;
		exit(EXIT_SUCCESS);
	}
}

/*=======================================================================*/
void	key_s(t_base *base)
{
	g_future_chara_index = g_index_chara + (line_length(base) + 1);
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
		base->g_y_chara += 50;
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
void	key_d(t_base *base)
{
	g_future_chara_index = g_index_chara + 1;
	if (check_walls(g_future_chara_index, base) == 0)
	{
		g_index_chara = g_future_chara_index;
		if (check_exit(g_index_chara, base) == 1)
		{
			if ((base->g_collected_coins) - 1 == base->tok_count)
				finishing();
		}
		mlx_destroy_image(base->mlx, base->xpm_img);
		base->xpm_img = mlx_xpm_file_to_image
			(base->mlx, base->floor, &base->width, &base->height);
		mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, \
		base->g_x_chara, base->g_y_chara);
		base->g_x_chara += 50;
		mlx_destroy_image(base->mlx, base->xpm_img);
		base->xpm_img = mlx_xpm_file_to_image
			(base->mlx, base->chara, &base->width, &base->height);
		mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, \
		base->g_x_chara, base->g_y_chara);
		if (check_coins(g_index_chara, base) == 1)
			base->g_collected_coins++;
		base->g_moves++;
		print_moves(base);
	}
}

/*=======================================================================*/
void	key_a(t_base *base)
{
	g_future_chara_index = g_index_chara - 1;
	if (check_walls(g_future_chara_index, base) == 0)
	{
		g_index_chara = g_future_chara_index;
		if (check_exit(g_index_chara, base) == 1)
		{
			if ((base->g_collected_coins) - 1 == base->tok_count)
				finishing();
		}
		mlx_destroy_image(base->mlx, base->xpm_img);
		base->xpm_img = mlx_xpm_file_to_image
			(base->mlx, base->floor, &base->width, &base->height);
		mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, \
		base->g_x_chara, base->g_y_chara);
		base->g_x_chara -= 50;
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