/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:28:33 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 14:55:06 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void size_error(t_map *map)
{
    ft_printf(2,"Error\n");
    ft_printf(2,"Invalid map size\n");
    free_array(map->array, map->y);
    free_array(map->copy, map->y);
    exit(EXIT_FAILURE);   
}

void error_map_elements(t_map *map)
{
    ft_printf(2,"Error\n");
    ft_printf(2,"Invalid map elements\n");
    free_array(map->array, map->y);
    free_array(map->copy, map->y);
    exit(EXIT_FAILURE);
}

void file_error(void)
{
    ft_printf(2,"Error\n");
    ft_printf(2,"The file extension isn't .ber\n");
    exit(EXIT_FAILURE);
}

void wall_error(t_map *map)
{
    ft_printf(2,"Error\n");
    ft_printf(2,"Wall failure\n");
    free_array(map->array, map->y);
    free_array(map->copy, map->y);
    exit(EXIT_FAILURE);
}

void open_error(void)
{
    ft_printf(2,"Error\n");
    ft_printf(2,"Open failed\n");
    exit(EXIT_FAILURE);
}
