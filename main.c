#include "./minilibx/mlx.h"
/*
 * 	we have an image but how exactly do we write pixels to this? For this we need to get 
 * the memory address on which we will mutate the bytes accordingly.
 * We retrieve this address as follows:
 */
	typedef struct	s_data 
	{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	}	t_data;



int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "First try");

	/* Creating new image to write the pixels inside of it. */ 
	img.img = mlx_new_image(mlx_ptr, 500, 300);

	/*
	 * After creating an image, we can call [mlx_get_data_addr]
	 * we pass [bits_per_pixel], [line_length], and [endian]. These will
	 * then be set accordingly for the *current* data address.
	 */
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*
	 * Now we have the image address, but still no pixels. Before we start with this, 
	 * we must understand that the bytes are not aligned, this means that the line_length differs 
	 * from the actual window width.
	 * We therefore should ALWAYS calculate the memory offset using the line length set by 
	 * [mlx_get_data_addr()]
	 */

	/**
	 * The [mlx_pixel_put()] function draws a defined pixel in the window (window_ptr)
	 * using the (x, y) coordinates, and the specified color.
	 */
	mlx_pixel_put(mlx_ptr, window_ptr, 5, 5, 0x00FF0000);
	mlx_loop(mlx_ptr);
	return (0);
}
