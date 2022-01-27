/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:17:08 by gabdoush          #+#    #+#             */
/*   Updated: 2022/01/27 18:21:36 by gabdoush         ###   ########.fr       */
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
/*-----------------------------------------------------------------------*/
void			error(int i);
/*-----------------------------------------------------------------------*/
void			line_numbers(char *str);
void			top_wall(char *str);
void			bottom_wall(char *str);
void			side_walls(char *str);
void			checking_map_walls(void);
/*-----------------------------------------------------------------------*/
#endif
