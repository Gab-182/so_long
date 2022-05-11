/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:33:17 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/11 21:54:02 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	base.win = mlx_new_window(base.mlx, base.g_col * 50, base.g_raw * 50, \
	"So_Long");
	just_drawing(&base);
	mlx_hook(base.win, 17, 1L << 2, closing_x, &base);
	mlx_hook(base.win, 02, 1L << 0, handle_moving, &base);
	mlx_loop(base.mlx);
	free(base.map);
	base.map = NULL;
}

/*=======================================================================*/
int	main(int argc, char **argv)
{
	char	*ext;
	char	*ptr;

	ext = "";
	ptr = ".ber";
	if (argc == 2)
	{
		ext = ft_strrchr(argv[1], '.');
		if (!ext)
			extension_error();
		if (ft_strcmp(ext, ptr) != 0)
			extension_error();
		check_top_walls(argv[1]);
		check_middle_walls(argv[1]);
		check_bottom_wall(argv[1]);
		checking_map_rectangle(argv[1]);
		map_drawer(argv[1]);
	}
	else
	{
		ft_printf("\nError, put only one (1) argument in your programe.\n");
		ft_printf("\n----> ./so_long {map_name.ber}<----\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*=======================================================================*/