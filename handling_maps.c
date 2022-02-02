/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:39:31 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 02:24:12 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Glopal variable */
int	x = 0;
int	y = 0;

int		col;
int		raw;

int		x_chara = 0;
int		y_chara = 0;

int		index_chara = 0;
int		future_chara_index = 0;

int		collected_coins = 0;
int		moves = 0;
/*=======================================================================*/
static 	int			closing_x(void);
static 	void		just_drawing(t_base *base);
static 	int  		handle_moving(int key, t_base *base);
static 	char		*map_reader(void);
static 	int			line_length(t_base *base);
static 	int			check_walls(int index, t_base *base);
static	int 		check_coins(int index_chara, t_base *base);
static	int			check_exit(int index_chara, t_base *base);
static void			col_raw(t_base *base);
/*=======================================================================*/
void			map_drawer(void)
{
	t_base	base;

	base.map = map_reader();
	base.wall = "./res/map_wall.xpm";
	base.floor = "./res/map_floor.xpm";
	base.chara = "./res/character_face.xpm";
	base.token = "./res/token.xpm";
	base.exit = "./res/exit.xpm";
	base.width = 1;
	base.height = 1;
	col_raw(&base);
	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, col * 50, raw * 50, "So_Long");
	just_drawing(&base);
	mlx_hook(base.win, 17, 1L<<2, closing_x, &base);
	mlx_hook(base.win, 02, 1L<<0, handle_moving, &base);
	mlx_loop(base.mlx);
	free(base.map);
	base.map = NULL;
}
/*=======================================================================*/
static char		*map_reader(void)
{
	int		i;
	int		fd;
	char	*map;
	char	*next_line;

	i = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	map = "";
	next_line = get_next_line(fd);
	while (map != NULL)
	{
		if (next_line == NULL)
			break ;
		map = ft_strjoin(map, next_line);
		next_line = get_next_line(fd);
	}
	if (next_line != NULL)
	{
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (map);
}
/*=======================================================================*/
static void		just_drawing(t_base *base)
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
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->wall, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			x += 50;
		}
		else if (base->map[i] == '\n')
		{
			y += 50;
			x = 0;
		}
		else if (base->map[i] == '0')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			x += 50;
		}
		else if (base->map[i] == 'P')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			x_chara = x;
			y_chara = y;
			index_chara = i;
			x += 50;
		}
		else if (base->map[i] == 'C')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->token, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			base->tok_count++;
			x += 50;
		}
		else if (base->map[i] == 'E')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->exit, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			x += 50;
		}
		else
			error(6, base->map);
		i++;
	}
}
/*=======================================================================*/
static int		handle_moving(int key, t_base *base)
{
	if (key == 0) //--A
	{
		future_chara_index = index_chara - 1;
		if (check_walls(future_chara_index, base) == 0)
		{
			index_chara = future_chara_index;
			if (check_exit(index_chara, base) == 1)
			{
				if (collected_coins == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			x_chara -= 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			if (check_coins(index_chara, base) == 1)
				collected_coins++;
			moves++;
			printf ("\033c");
			printf("moves :%d\n", moves);
		}
	}
	if (key == 1) //--S
	{
		future_chara_index = index_chara + (line_length(base) + 1);
		if (check_walls(future_chara_index, base) == 0)
		{
			index_chara = future_chara_index;
			if (check_exit(index_chara, base) == 1)
			{
				if (collected_coins == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			y_chara += 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			if (check_coins(index_chara, base) == 1)
				collected_coins++;
			moves++;
			printf ("\033c");
			printf("moves :%d\n", moves);
		}
	}
	if (key == 2) //--D
	{
		future_chara_index = index_chara + 1;
		if (check_walls(future_chara_index, base) == 0)
		{
			index_chara = future_chara_index;
			if (check_exit(index_chara, base) == 1)
			{
				if (collected_coins == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			x_chara +=  50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			if (check_coins(index_chara, base) == 1)
				collected_coins++;
			moves++;
			printf ("\033c");
			printf("moves :%d\n", moves);
		}
	}
	if (key == 13) //-W
	{
		future_chara_index = index_chara - (line_length(base) + 1);
		if (check_walls(future_chara_index, base) == 0)
		{
			index_chara = future_chara_index;
			if (check_exit(index_chara, base) == 1)
			{
				if (collected_coins == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			y_chara -= 50;;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x_chara, y_chara);
			if (check_coins(index_chara, base) == 1)
				collected_coins++;
			moves++;
			printf ("\033c");
			printf("moves :%d\n", moves);
		}
	}
	if (key == 53) //-ESC
		exit(EXIT_SUCCESS);
	return (0);
}
/*=======================================================================*/
static int		closing_x(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
/*=======================================================================*/
static int		line_length(t_base *base)
{
	int line_len;
	line_len = 0;
	while (base->map[line_len] != '\0' && base->map[line_len] != '\n')
		line_len++;
	return (line_len);
}
/*=======================================================================*/
static int		check_walls(int future_chara_index, t_base *base)
{
	if (base->map[future_chara_index] == 'E' && collected_coins != base->tok_count)
		return (1);
	if (base->map[future_chara_index] == '1')
		return (1);
	return (0);
}
/*=======================================================================*/
static int		check_coins(int index_chara, t_base *base)
{
	if (base->map[index_chara] == 'C')
	{
		base->map[index_chara] = '0';
		return (1);
	}
	return (0);
}
/*=======================================================================*/
static int		check_exit(int index_chara, t_base *base)
{
	if (base->map[index_chara] == 'E')
		return (1);
	return (0);
}
/*=======================================================================*/
static void		col_raw(t_base *base)
{
	int	i;

	i = 0;
	while (base->map[i] != '\0')
	{
		if (base->map[i] == '1')
			col += 1;
		else if (base->map[i] == '\n')
		{
			raw += 1;
			col = 0;
		}
		else if (base->map[i] == '0')
			col += 1;
		else if (base->map[i] == 'P')
			col += 1;
		else if (base->map[i] == 'C')
			col += 1;
		else if (base->map[i] == 'E')
			col += 1;
		i++;
	}
	raw += 1;
}
// /*=======================================================================*/