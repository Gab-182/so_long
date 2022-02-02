/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:33:17 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 02:20:40 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	char	*ext;
// 	//char	*ptr;
	
// 	ext = ft_strrchr(argv[2], '.');
// 	printf("%s\n", ext);
// 	// ptr = ".ber";
// 	// if (argc == 2)
// 	// {
// 	// 	if (ext != ptr)
// 	// 		extension_error();
// 	// 	// checking_map_rectangle();
// 	// 	// check_top_walls();
// 	// 	// check_middle_walls();
// 	// 	// check_bottom_wall();
// 	// 	// map_drawer();
// 	// }
// 	// else
// 	// 	return(EXIT_FAILURE);
// 	return(EXIT_SUCCESS);
// }

int	main(int argc, char **argv)
{
	char	*ext;
	ext = "";
	if (argc == 2)
		ext = ft_strrchr(argv[1], '.');
		
	printf("%s\n", ext);
	//exit(1);
	// checking_map_rectangle();
	// check_top_walls();
	// check_middle_walls();
	// check_bottom_wall();
	//map_drawer();
	return (EXIT_SUCCESS);
}
