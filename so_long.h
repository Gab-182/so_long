/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:08 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 09:36:06 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*-----------------------------------------------------------------------*/
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"

/*-----------------------------------------------------------------------*/
typedef struct s_base
{
	void	*mlx;
	void	*win;
	void	*xpm_img;

	char	*wall;
	char	*floor;

	char	*chara;
	int		g_moves;

	char	*token;
	int		tok_count;
	int		g_collected_coins;

	char	*exit;

	int		width;
	int		height;

	char	*map;
	int		g_col;
	int		g_raw;

	int		g_x_chara;
	int		g_y_chara;
}		t_base;
/*-----------------------------------------------------------------------*/
# define KEY_ESC	53
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13

/*-----------------------------------------------------------------------*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;
/*----------------------so_long_utils_1-----------------------------------*/
void			ft_putchar(int c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			error(int i, char *buffer);
void			extension_error(void);
/*---------------------so_long_utils_2------------------------------------*/
char			*ft_strrchr(char *s, int c);
int				ft_strcmp(char *s1, char *s2);
/*-----------------------------------------------------------------------*/
void			check_bottom_wall(char *map_file);
void			check_middle_walls(char *map_file);
void			checking_map_rectangle(char *map_file);
void			check_top_walls(char *map_file);
void			exit_checker(t_base *base);
void			coin_checker(t_base *base);
void			position_checker(t_base *base);
//void			line_count(t_base *base);
/*------------------------at_least_checker-------------------------------*/
void			col_raw(t_base *base);
int				check_exit(int index_chara, t_base *base);
int				check_coins(int index_chara, t_base *base);
int				check_walls(int future_chara_index, t_base *base);
int				line_length(t_base *base);
/*---------------------------Keys----------------------------------------*/
void			closing_esc(int key);
int				closing_x(void);
/*--------------------------map_indexes----------------------------------*/
/*------------------------handling_maps----------------------------------*/
void			map_drawer(char *map_file);
char			*map_reader(char *map_file);
int				handle_moving(int key, t_base *base);
void			just_drawing(t_base *base);
/*-----------------------------------------------------------------------*/
#endif
