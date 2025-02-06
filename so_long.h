/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:29:34 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/06 18:32:25 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H
#   include "ft_libft/libft.h"
#   include "ft_printf/ft_printf.h"
#   include "MLX42/MLX42.h"
#   define WIDTH 500
#   define HEIGHT 500

typedef struct mlx_conex
{
    void *window;
    void *context;
    int32_t width;
    int32_t height;
    double deta;

}       mlx_conex;

#endif