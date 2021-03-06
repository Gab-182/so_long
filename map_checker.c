/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:44:13 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 17:01:00 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_bottom_wall(char *map_file)
{
	int		fd;
	int		i;
	char	*line;
	char	*last_line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	last_line = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		last_line = line;
	}
	while (last_line && last_line[i] != '\0')
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
void	check_middle_walls(char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
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
void	check_top_walls(char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (!line || line[0] == '\0' || ft_strlen(line)
		< 3 || get_next_line(fd) == NULL)
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
void	checking_map_rectangle(char *map_file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(map_file, O_RDONLY);
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