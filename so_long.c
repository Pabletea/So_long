/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:32:40 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/10 10:49:27 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static mlx_image_t* image;

int main(int ar, char **av)
{
    if(ar != 2)
        return(ft_printf(2,"Error: invalid arg number\n"));
    if(ft_strnstr(av[1],".ber",ft_strlen(av[1])) == NULL)
        return(ft_printf(2,"Error: invalid map type\n"));
    if(validate_map(av[1]) == -1)
        
}