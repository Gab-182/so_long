/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:47:24 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/11 21:37:45 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

extern int	g_x;
extern int	g_y;

extern int	g_index_chara;
extern int	g_future_chara_index;

/*=======================================================================*/
void	map_wall(t_base *base)
{
	int	i;

	i = 0;
	if (i > 0)
		mlx_destroy_image(base->mlx, base->xpm_img);
	base->xpm_img = mlx_xpm_file_to_image
		(base->mlx, base->wall, &base->width, &base->height);
	mlx_put_image_to_window
		(base->mlx, base->win, base->xpm_img, g_x, g_y);
	g_x += 50;
	i++;
}

/*=======================================================================*/
void	map_floor(t_base *base)
{
	mlx_destroy_image(base->mlx, base->xpm_img);
	base->xpm_img = mlx_xpm_file_to_image
		(base->mlx, base->floor, &base->width, &base->height);
	mlx_put_image_to_window
		(base->mlx, base->win, base->xpm_img, g_x, g_y);
	g_x += 50;
}

/*=======================================================================*/
void	map_char(t_base *base, int i)
{
	mlx_destroy_image(base->mlx, base->xpm_img);
	base->xpm_img = mlx_xpm_file_to_image
		(base->mlx, base->chara, &base->width, &base->height);
	mlx_put_image_to_window
		(base->mlx, base->win, base->xpm_img, g_x, g_y);
	base->g_x_chara = g_x;
	base->g_y_chara = g_y;
	g_index_chara = i;
	g_x += 50;
}

/*=======================================================================*/
void	map_coins(t_base *base)
{
	mlx_destroy_image(base->mlx, base->xpm_img);
	base->xpm_img = mlx_xpm_file_to_image
		(base->mlx, base->token, &base->width, &base->height);
	mlx_put_image_to_window
		(base->mlx, base->win, base->xpm_img, g_x, g_y);
	base->tok_count++;
	g_x += 50;
}

/*=======================================================================*/
void	map_exit(t_base *base)
{
	mlx_destroy_image(base->mlx, base->xpm_img);
	base->xpm_img = mlx_xpm_file_to_image
		(base->mlx, base->exit, &base->width, &base->height);
	mlx_put_image_to_window
		(base->mlx, base->win, base->xpm_img, g_x, g_y);
	g_x += 50;
}

/*=======================================================================*/