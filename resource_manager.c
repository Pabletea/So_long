/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:14:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 21:42:02 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void map_printer(t_map *map)
{
    int y = 0;
    while (y < map->y)
    {
        int x = 0;
        while (x < map->x)
        {
            mlx_image_t *img = NULL;
            if (map->array[y][x] == '0')
                img = map->img.empty;
            else if (map->array[y][x] == '1')
                img = map->img.wall;
            else if (map->array[y][x] == 'E')
                img = map->img.exit;
            else if (map->array[y][x] == 'C')
                img = map->img.collectible;
            else if (map->array[y][x] == 'P')
                img = map->img.player_down1;            
            if (img)
                mlx_image_to_window(map->mlx, img, x * PXL_IMG, y * PXL_IMG);
            x++;
        }
        y++;
    }
}


void file_to_image_player(t_map *map)
{
    map->img.player_left1 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_left1.png"));
    map->img.player_right1 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_right1.png"));
    map->img.player_up1 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_up1.png"));
    map->img.player_down1 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_down1.png"));
    map->img.player_left2 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_left1.png"));
    map->img.player_right2 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_right1.png"));
    map->img.player_up2 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_up1.png"));
    map->img.player_down2 = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/player/player_down1.png"));
}

void file_to_image(t_map *map)
{
    map->img.empty = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/map/empty.png"));
    map->img.wall = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/map/wall.png"));
    map->img.exit = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/map/exit_closed.png"));
    map->img.collectible = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/map/collectible.png"));
    map->img.enemy = mlx_texture_to_image(map->mlx, mlx_load_png("./resources/textures/map/enemy.png"));
    
    file_to_image_player(map);
}



