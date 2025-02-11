/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:40:25 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 18:40:43 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_resume(t_map *map, int x, int y, int direction)
{
    if (direction == UP)
        mlx_image_to_window(map->mlx, map->img.player_up2, x * PXL_IMG, y * PXL_IMG);
    else if (direction == DOWN)
        mlx_image_to_window(map->mlx, map->img.player_down2, x * PXL_IMG, y * PXL_IMG);
    else if (direction == LEFT)
        mlx_image_to_window(map->mlx, map->img.player_left2, x * PXL_IMG, y * PXL_IMG);
    else if (direction == RIGHT)
        mlx_image_to_window(map->mlx, map->img.player_right2, x * PXL_IMG, y * PXL_IMG);
}