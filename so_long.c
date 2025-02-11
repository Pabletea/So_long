/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:32:40 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 11:16:58 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static mlx_image_t* image;

int main(int ar, char **av)
{
    t_map map;

    if (ar == 2)
    {

        map_initializer(&map, av);
        validate_map(&map);

        // map.mlx = mlx_init(WIDTH,HEIGHT,"So long",false);

    }
    exit(EXIT_FAILURE);
}