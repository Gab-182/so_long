/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:39:31 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 14:22:10 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Glopal variable */
int	g_x = 0;
int	g_y = 0;

int	g_index_chara = 0;
int	g_future_chara_index = 0;

/*=======================================================================*/
void	map_drawer(char *map_file)
{
	t_base	base;

	base.map = map_reader(map_file);
	base.wall = "./res/map_wall.xpm";
	base.floor = "./res/map_floor.xpm";
	base.chara = "./res/character_face.xpm";
	base.token = "./res/token.xpm";
	base.exit = "./res/exit.xpm";
	base.width = 1;
	base.height = 1;
	col_raw(&base);
	base.mlx = mlx_init();
	base.win = mlx_new_window
		(base.mlx, base.g_col * 50, base.g_raw * 50, "So_Long");
	just_drawing(&base);
	mlx_hook(base.win, 17, 1L << 2, closing_x, &base);
	mlx_hook(base.win, 02, 1L << 0, handle_moving, &base);
	mlx_loop(base.mlx);
	free(base.map);
	base.map = NULL;
}

/*=======================================================================*/
char	*map_reader(char *map_file)
{
	int		i;
	int		fd;
	char	*map;
	char	*next_line;

	i = 0;
	fd = open(map_file, O_RDONLY);
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
		{
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->wall, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img, g_x, g_y);
			g_x += 50;
		}
		else if (base->map[i] == '\n')
		{
			g_y += 50;
			g_x = 0;
		}
		else if (base->map[i] == '0')
		{
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img, g_x, g_y);
			g_x += 50;
		}
		else if (base->map[i] == 'P')
		{
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img, g_x, g_y);
			base->g_x_chara = g_x;
			base->g_y_chara = g_y;
			g_index_chara = i;
			g_x += 50;
		}
		else if (base->map[i] == 'C')
		{
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->token, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img, g_x, g_y);
			base->tok_count++;
			g_x += 50;
		}
		else if (base->map[i] == 'E')
		{
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->exit, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img, g_x, g_y);
			g_x += 50;
		}
		else
			error(6, base->map);
		i++;
	}
}

/*=======================================================================*/
int	handle_moving(int key, t_base *base)
{
	if (key == 0)
	{
		g_future_chara_index = g_index_chara - 1;
		if (check_walls(g_future_chara_index, base) == 0)
		{
			g_index_chara = g_future_chara_index;
			if (check_exit(g_index_chara, base) == 1)
			{
				if ((base->g_collected_coins) - 1 == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			base->g_x_chara -= 50;
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			if (check_coins(g_index_chara, base) == 1)
				base->g_collected_coins++;
			base->g_moves++;
			printf ("\033c");
			printf("moves :%d\n", base->g_moves);
		}
	}
	if (key == 1)
	{
		g_future_chara_index = g_index_chara + (line_length(base) + 1);
		if (check_walls(g_future_chara_index, base) == 0)
		{
			g_index_chara = g_future_chara_index;
			if (check_exit(g_index_chara, base) == 1)
			{
				if ((base->g_collected_coins) - 1 == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			base->g_y_chara += 50;
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			if (check_coins(g_index_chara, base) == 1)
				base->g_collected_coins++;
			base->g_moves++;
			printf ("\033c");
			printf("moves :%d\n", base->g_moves);
		}
	}
	if (key == 2)
	{
		g_future_chara_index = g_index_chara + 1;
		if (check_walls(g_future_chara_index, base) == 0)
		{
			g_index_chara = g_future_chara_index;
			if (check_exit(g_index_chara, base) == 1)
			{
				if ((base->g_collected_coins) - 1 == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			base->g_x_chara += 50;
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			if (check_coins(g_index_chara, base) == 1)
				base->g_collected_coins++;
			base->g_moves++;
			printf ("\033c");
			printf("moves :%d\n", base->g_moves);
		}
	}
	if (key == 13)
	{
		g_future_chara_index = g_index_chara - (line_length(base) + 1);
		if (check_walls(g_future_chara_index, base) == 0)
		{
			g_index_chara = g_future_chara_index;
			if (check_exit(g_index_chara, base) == 1)
			{
				if ((base->g_collected_coins) - 1 == base->tok_count)
				{
					printf("Congratulations, the game is finished now.\n");
					exit(EXIT_SUCCESS);
				}
			}
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);
			base->g_y_chara -= 50;
			base->xpm_img = mlx_xpm_file_to_image
				(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window
				(base->mlx, base->win, base->xpm_img,
				base->g_x_chara, base->g_y_chara);

			if (check_coins(g_index_chara, base) == 1)
				base->g_collected_coins++;
			base->g_moves++;
			printf ("\033c");
			printf("moves :%d\n", base->g_moves);
		}
	}
	closing_esc(key);
	return (0);
}
/*=======================================================================*/
