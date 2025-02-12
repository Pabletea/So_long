/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:32:40 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 20:03:07 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ar, char **av)
{
	t_map	map;

	if (ar == 2)
	{
		map_initializer(&map, av);
		validate_map(&map);
		map.mlx = mlx_init(map.x * PXL_IMG, map.y * PXL_IMG, WIN_NAME, true);
		map.wnd = mlx_new_image(map.mlx, map.x * PXL_IMG, map.y * PXL_IMG);
		mlx_image_to_window(map.mlx, map.wnd, 0, 0);
		file_to_image(&map);
		map_printer(&map);
		mlx_key_hook(map.mlx, key_hook_func, &map);
		mlx_loop(map.mlx);
		mlx_terminate(map.mlx);
	}
	else
		ft_printf(2, "Wrong number of arguments\n");
	exit(EXIT_FAILURE);
}
