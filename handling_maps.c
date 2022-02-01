#include "so_long.h"

int	x = 0;
int	y = 0;



/*-----------------------------------------------------------------------*/
static int		closing_x(void);
static void		just_drawing(t_base *base);
static int  	handle_moving(int key, t_base *base);
static char		*map_reader(void);
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

	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, 1000, 1000, "So_Long");

	just_drawing(&base);

	mlx_hook(base.win, 17, 1L<<2, closing_x, &base);
	mlx_hook(base.win, 02, 1L<<0, handle_moving, &base);

	mlx_loop(base.mlx);

	free(base.map);
	base.map = NULL;
}
/*=======================================================================*/
static char    *map_reader(void)
{
	int		i;
	int		fd;
	char	*map;
	char    *next_line;

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
/*-----------------------------------------------------------------------*/
static void		just_drawing(t_base *base)
{
	int	i;

	i = 0;
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
		else if (base->map[i] == 'p')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			base->x_chara = x;
			base->y_chara = y;
			x += 50;
		}
		else if (base->map[i] == 'c')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->token, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, x, y);
			x += 50;
		}
		 else if (base->map[i] == 'e')
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
/*-----------------------------------------------------------------------*/
static int  	handle_moving(int key, t_base *base)
{
	if (key == 0) //A
	{
		printf("I just pressed [A]\n");
		if ( != '1')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
			base->x_chara -= 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
		}
	}
	if (key == 1) //S
	{
		printf("I just pressed [S]\n");
		if ( != '1')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
			base->y_chara += 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
		}
	}
	if (key == 2) //D
	{
		printf("I just pressed [D]\n");
		if ( != '1')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
			base->x_chara += 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
		}
	}
	if (key == 13) //W
	{
		printf("I just pressed [W]\n");
		if ( != '1')
		{
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->floor, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
			base->y_chara -= 50;
			base->xpm_img = mlx_xpm_file_to_image(base->mlx, base->chara, &base->width, &base->height);
			mlx_put_image_to_window(base->mlx, base->win, base->xpm_img, base->x_chara, base->y_chara);
		}
	}
	if (key == 53) //ESC
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
/*-----------------------------------------------------------------------*/
// static void		moving_character(int x_char, int y_char, t_base base)
// {
// 	int	i;

// 	i = 0;
// 	while (base.map[i] != '\0')
// 	{
// 		if (base.map[i] == 'p')
// 		{
// 			base.xpm_img = mlx_xpm_file_to_image(base.mlx, base.floor, &base.width, &base.height);
// 			mlx_put_image_to_window(base.mlx, base.win, base.xpm_img, x_char, y_char);

// 			mlx_hook(base.win, 17, 1L<<2, closing_x, &base);
// 			mlx_hook(base.win, 02, 1L<<0, handle_moving, &base);
// 			mlx_loop(base.mlx);
// 		}
// 		i++;
// 	}

// }
/*-----------------------------------------------------------------------*/
static int		closing_x(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
/*-----------------------------------------------------------------------*/
