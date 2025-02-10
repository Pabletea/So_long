/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:57 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/10 11:16:00 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



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