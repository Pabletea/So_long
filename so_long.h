/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:29:34 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 11:27:47 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   include <stdio.h>
#   include <stdlib.h>
#   include <stdbool.h>
#	include <fcntl.h>
#   define SO_LONG_H
#   include "ft_libft/libft.h"
#   include "ft_printf/ft_printf.h"
#   include "MLX42/MLX42.h"
#   define WIDTH 512
#   define HEIGHT 512

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player_left1;
	void	*player_right1;
	void	*player_up1;
	void	*player_down1;
	void	*player_left2;
	void	*player_right2;
	void	*player_up2;
	void	*player_down2;
	void	*enemy;
}t_img;

typedef struct s_player
{
	int	y;
	int	x;

}t_player;

typedef struct mlx_conex
{
    void *window;
    void *context;
    int32_t width;
    int32_t height;
    double deta;

}       mlx_conex;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	mlx_image_t		img;
	t_player	player;

}t_map;

void validate_map(t_map *map);
void free_array(char **arr, int i);
void size_error();
void map_initializer(t_map *map, char **av);
void check_size(t_map *map);
void    check_player(t_map *map);
void change_route(int x, int y, t_map *map);
void check_route(t_map *map);
void    check_param(t_map *map);

void error_map_elements(t_map *map);
void file_error(void);
void wall_error(t_map *map);

#endif