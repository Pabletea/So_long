/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:28:33 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 12:13:32 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void size_error(t_map *map)
{
    ft_printf(2,"Error: invalid map size");
    free_array(map->array, map->y);
    free_array(map->array, map->y);
    exit(EXIT_FAILURE);   
}

void error_map_elements(t_map *map)
{
    ft_printf(2,"Error: invalid map elements");
    free_array(map->array, map->y);
    free_array(map->array, map->y);
    exit(EXIT_FAILURE);
}

void file_error(void)
{
    ft_printf(2,"Error: The file extension isn't BER");
    exit(EXIT_FAILURE);
}

void wall_error(t_map *map)
{
    ft_printf(2,"Error: Wall failure");
    free_array(map->array, map->y);
    free_array(map->array, map->y);
    exit(EXIT_FAILURE);
}

void open_error(void)
{
    ft_printf(2,"Error: open failed");
    exit(EXIT_FAILURE);
}
