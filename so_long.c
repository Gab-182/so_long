#include "so_long.h"
/*------------------------------------------------------------------------------------------*/
/* Global variable to manublate through del_key function. */
//int	i = 0;
/*------------------------------------------------------------------------------------------*/
// int	del_key()
// {
// 	i++;
// 	ft_putstr("\033c");
// 	ft_putnbr(i);
// 	return (0);
// }
/*------------------------------------------------------------------------------------------*/
int	main(void)
{
	// checking_map_rectangle();
	// check_top_walls();
	// check_bottom_wall();
	// check_middle_walls();
	
	map_drawer();
// 	//checking_map_walls();
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*xpm_img;
// 	char	*file_name;
// 	int		width;
// 	int		height;
// 	t_data	img;

// 	file_name = "./res/box.xpm";
// 	width = 500;
// 	height = 500;
// /*------------------------------------------------------------------------------------------*/
// /*[1]
// ** Initialize mlx.
// **
// ** @return	void*
// */
// 	mlx_ptr = mlx_init();
// /*[2]
// ** Create a new window.
// **
// ** @param	void *mlx_ptr	the mlx instance pointer;
// ** @param	int  size_x		the width of the window;
// ** @param	int  size_y		the height of the window;
// ** @param	char *title		the title of the window;
// ** @return	void*			the window instance pointer.
// */
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "So<--------->Long");
// /*[3]
// ** Create a new MLX compatible image.
// **
// ** @param	void *mlx_ptr	the mlx instance pointer;
// ** @param	int  width		the width of the image to be created;
// ** @param	int  height		the height of the image to be created;
// ** @return	void*			the image instance reference.
// */
// 	img.img = mlx_new_image(mlx_ptr, 500, 500);
// /*[4]
// ** Gets the data address of the current image.
// **
// ** @param	void *img_ptr			the image instance;
// ** @param	int  *bits_per_pixel	a pointer to where the bpp is written;
// ** @param	int  *size_line		a pointer to where the line is written;
// ** @param	int  *endian		a pointer to where the endian is written;
// ** @return	char*				the memory address of the image.
// */
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// /*[5]
// ** Put a pixel on the screen.
// **
// ** @param	void *mlx_ptr	the mlx instance pointer;
// ** @param	void *win_ptr	the window instance pointer;
// ** @param	int  x			the x coordinate of the pixel to draw;
// ** @param	int  y			the y coordinate of the pixel to draw;
// ** @param	int  color		the color of the pixel to draw (0xTTRRGGBB);
// ** @return	int				has no return value (bc).
// */
// 	mlx_pixel_put(mlx_ptr, win_ptr, 5, 5, 0x00FF0000);
// /*[6]
// ** Put an image to the given window.
// **
// ** @param	void *mlx_ptr	the mlx instance;
// ** @param	void *win_ptr	the window instance;
// ** @param	void *img_ptr	the image instance pointer;
// ** @param	int  x			the x location of where the image ought to be placed;
// ** @param	int  y			the y location of where the image ought to be placed;
// ** @return	int				has no return value (bc).
// */
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
// /*[7]
// ** Put a string in the window.
// **
// ** @param	void *mlx_ptr	the mlx instance;
// ** @param	void *win_ptr	the window instanse;
// ** @param	int  x			the x location;
// ** @param	int  y			the y location;
// ** @param	int  color		the font color;
// ** @param	char *string	the text to write;
// ** @return	int				has no return value (bc).
// */
// 	mlx_string_put(mlx_ptr, win_ptr, 100, 100, 0x00FF0000, "Hello World!!");
// /*[8]
// ** Hook into key events.
// **
// ** @param	void *win_ptr	the window instance;
// ** @param	int  (*f)()		the handler function, will be called as follows:
// **							(*f)(int key_code, void *param);
// ** @param	void *param		the parameter to give on each event;
// ** @return	int				has no return value (bc).
// */
// 	mlx_key_hook(win_ptr, del_key, (void *)0);
// /*------------------------------------------------------------------------------------------*/
// /*[9]
// ** Convert an xpm file to a new image instance.
// **
// ** @param	void *mlx_ptr	the mlx instance;
// ** @param	char *filename	the file to load;
// ** @param	int  *width		a pointer to where the width ought to be written;
// ** @param	int  *height	a pointer to where the height ought to be written;
// ** @return	void*			the image instance.
// */
// 	xpm_img = mlx_xpm_file_to_image(mlx_ptr, file_name, &width, &height);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, xpm_img, 0, 0);
// 	mlx_loop(mlx_ptr);
	
	return (EXIT_SUCCESS);
}
