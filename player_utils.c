/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:29:48 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 11:09:10 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_player(t_map *map)
{
    map->player.y = 0;
    map->player.x = 0;
    while(map->player.y < map->x)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

void change_route(int x, int y, t_map *map)
{
    char c;

    c = map->copy[y][x];
    if(c == 'C')
    {
        map->c_check -= 1;
        map->copy[y][x] = '1';
    }
	else if (c == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (c == '0' || c == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	change_route(x + 1, y, map);
	change_route(x - 1, y, map);
	change_route(x, y + 1, map);
	change_route(x, y - 1, map);
}
