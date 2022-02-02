/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:08 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/02 22:37:40 by gabdoush         ###   ########.fr       */
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
	char	*token;
	int		tok_count;

	char	*exit;
	
	int		width;
	int		height;
	
	char	*map;
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
/*-----------------------------------------------------------------------*/
void			ft_putchar(int c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			error(int i, char *buffer);
/*-----------------------------------------------------------------------*/
void			check_bottom_wall(void);
void			check_middle_walls(void);
void			checking_map_rectangle(void);
void			check_top_walls(void);
/*-----------------------------------------------------------------------*/
void			map_drawer(void);

#endif
