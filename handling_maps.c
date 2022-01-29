#include "so_long.h"


/*-----------------------------------------------------------------------*/
static int	closing_x(void) //t_base base
{
	//mlx_destroy_window(base.mlx, base.win);
	exit(EXIT_SUCCESS);
	return (0);
}
/*-----------------------------------------------------------------------*/
static int	closing_esc(int key) // , t_base base
{
	if (key == 53)
	{
		//mlx_destroy_window(base.mlx, base.win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
void    map_drawer(void)
{
	int		fd;
	int		i;
	int		x;
	int		y;
	char	*buffer;
	t_base	base;
	int		width;
	int		height;

	void	*xpm_img1;
/*-----------------------------------------------------------------------*/
	base.wall = "./res/map_wall.xpm";
	base.gap = "./res/map_gap.xpm";
	base.char_face = "./res/character_face.xpm";
	width = 1;
	height = 1;
	i = 0;
	x = 0;
	y = 0;
/*-----------------------------------------------------------------------*/
	base.mlx = mlx_init();
	base.win = mlx_new_window(base.mlx, 2000, 1500, "So<--------->Long");
/*-----------------------------------------------------------------------*/
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd = open("./maps/map.ber", O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	buffer[ft_strlen(buffer)] = '\0';
/*-----------------------------------------------------------------------*/
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '1')
		{
			base.xpm_img = mlx_xpm_file_to_image(base.mlx, base.wall, &width, &height);
			mlx_put_image_to_window(base.mlx, base.win, base.xpm_img, x, y);
			i++;
			x += 50;
		}
		else if (buffer[i] == '\n')
		{
			y += 50;
			x = 0;
			i++;
		}
		else if (buffer[i] == '0')
		{
			base.xpm_img = mlx_xpm_file_to_image(base.mlx, base.gap, &width, &height);
			mlx_put_image_to_window(base.mlx, base.win, base.xpm_img, x, y);
			i++;
			x += 50;
		}
	}
/*-----------------------------------------------------------------------*/
	mlx_hook(base.win, 17, 1L<<2, closing_x, &base); //for killing in "mouse" press.
	mlx_hook(base.win, 2, 1L<<5, closing_esc, &base); //for killing in "esc" press.
/*-----------------------------------------------------------------------*/
	mlx_loop(base.mlx);
	free(buffer);
	buffer = NULL;
	close(fd);
/*-----------------------------------------------------------------------*/
}
