/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:51:20 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 14:01:17 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void manage_exit(t_map *map)
{
    if (map->exit == 1)
    {
        mlx_image_to_window(map->mlx, map->img.exit_open, map->x * PXL_IMG, map->y * PXL_IMG);
    }
    return ;
}

void key_hook_func(mlx_key_data_t keydata, void *param)
{
    t_map *map = (t_map *)param;
    
    if (keydata.action == MLX_PRESS)
    {
        check_player(map);
        
        if (keydata.key == MLX_KEY_ESCAPE)
            close_game(map);
        
        // Si la salida está desbloqueada, actualiza el sprite pero permite movimiento
        if (map->exit == 1)
            manage_exit(map);
        
        // Sigue permitiendo el movimiento aunque la salida esté desbloqueada
        if (keydata.key == LEFT)
            move_left(map);
        else if (keydata.key == DOWN)
            move_down(map);
        else if (keydata.key == RIGHT)
            move_right(map);
        else if (keydata.key == UP)
            move_up(map);
    }
}

