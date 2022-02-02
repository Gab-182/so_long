/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:44:13 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/01 12:25:48 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*-----------------------------------------------------------------------*/
void	check_bottom_wall(void)
{
	int		fd;
	int		i;
	char	*line;
	char	*last_line;

	i = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		last_line = get_next_line(fd);
	}
	while (last_line[i] != '\0' && last_line[i] != '\n')
	{
		if (last_line[i] != '1')
			error(4, last_line);
		i++;
	}
	free(last_line);
	last_line = NULL;
	close(fd);
}

/*-----------------------------------------------------------------------*/
void	check_middle_walls(void)
{
	int		fd;
	char	*line;

	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			error(3, line);
	}
	free(line);
	line = NULL;
	close(fd);
}

/*-----------------------------------------------------------------------*/
void	check_top_walls(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		error(2, line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
			error(2, line);
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
}

/*-----------------------------------------------------------------------*/
void	checking_map_rectangle(void)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line[i] != '\n')
		i++;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		j = 0;
		while (line[j] != '\0' && line[j] != '\n')
			j++;
		if (j != i)
			error(1, line);
	}
	free(line);
	line = NULL;
	close(fd);
}
/*-----------------------------------------------------------------------*/