/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:44:13 by gabdoush          #+#    #+#             */
/*   Updated: 2022/01/27 18:15:14 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*-----------------------------------------------------------------------*/

void	line_numbers(char *str)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	line++;
	if (line < 3)
		error(1);
}
/*-----------------------------------------------------------------------*/

void	top_wall(char *str)
{
	int	i;
	int	top_wall_len;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	top_wall_len = i - 1;
	while (top_wall_len >= 0)
	{
		if (str[top_wall_len] == '1')
			top_wall_len--;
		else
			error(2);
	}
	top_wall_len = i - 1;
}
/*-----------------------------------------------------------------------*/

void	bottom_wall(char *str)
{
	int	i;
	int	bottom_wall_len;
	int	top_wall_len;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	top_wall_len = i - 1;
	bottom_wall_len = ft_strlen(str) - top_wall_len - 1;
	while (str[bottom_wall_len] != '\0')
	{
		if (str[bottom_wall_len] == '1')
			bottom_wall_len++;
		else
			error(3);
	}
}
/*-----------------------------------------------------------------------*/

void	side_walls(char *str)
{
	int	top_wall_len;
	int	first_point;
	int	line_len;
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	top_wall_len = i - 1;
	first_point = top_wall_len + 2;
	line_len = top_wall_len;
	while (str[first_point])
	{
		if (str[first_point] == '1')
			first_point = first_point + line_len;
		else
			error(4);
		if (str[first_point] == '1')
			first_point = first_point + 2;
		else
			error(4);
	}
}
/*-----------------------------------------------------------------------*/

void	checking_map_walls(void)
{
	int		fd;
	char	*str;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd = open("./maps/map.ber", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	buffer[ft_strlen(buffer)] = '\0';
	str = buffer;
	line_numbers(str);
	top_wall(str);
	bottom_wall(str);
	side_walls(str);
	free(str);
	close(fd);
}
