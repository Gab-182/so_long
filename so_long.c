/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:33:17 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/03 10:31:17 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	char	*ext;
	char	*ptr;
	
	ext = "";
	ptr = ".ber";
	if (argc == 2)
	{
		ext = ft_strrchr(argv[1], '.');
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
			printf("\nError, put only one (1) argument in your programe.\n");
			printf("\n----> ./so_long {map_name.ber}<----\n");
			exit(EXIT_FAILURE);
		}
	return (EXIT_SUCCESS);
}
