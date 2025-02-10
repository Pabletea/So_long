/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:57 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/10 12:31:28 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void map_initializer(t_map *map, char **av)
{
    map->file = av[1];
    map->moves = 0;
    map->e = 0;
    map->collec = 0;
    map->p = 0;
    map->y = 0;
    map->player.y = 0;
    map->player.x = 0;
    map->exit = 0;
}



int validate_map(t_map *map)
{
    int y;
    int x;
    int max;

    y = 0;
    x = 0;
    max = ft_strlen(map->array[y]);
    while (y < map->y)
    {
        x = ft_strlen(map->array[y]);
        if (max != x)
        y++;
    }
    map->x = max;
    
}