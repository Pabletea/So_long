/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:51:20 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 21:55:49 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void key_hook_func(mlx_key_data_t keydata, void *param)
{
    t_map *map = (t_map *)param;
    
    if (keydata.action == MLX_PRESS)
    {
        check_player(map);
        if (keydata.key == MLX_KEY_ESCAPE)
            close_game(map);
        else if (map->exit == 1)
            return;
        else if (keydata.key == LEFT)
            move_left(map);
        else if (keydata.key == DOWN)
            move_down(map);
        else if (keydata.key == RIGHT)
            move_right(map);
        else if (keydata.key == UP)
            move_up(map);
    }
}