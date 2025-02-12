/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:29:34 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 22:13:52 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define SO_LONG_H
# include "../ft_libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "MLX42/MLX42.h"
# define PXL_IMG 50
# define WIN_NAME "so_long"
# define UP MLX_KEY_W
# define DOWN MLX_KEY_S
# define LEFT MLX_KEY_A
# define RIGHT MLX_KEY_D
# define ESC 53

typedef struct s_img
{
	void		*empty;
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*exit_open;
	void		*player_left1;
	void		*player_right1;
	void		*player_up1;
	void		*player_down1;
	void		*player_down_basic1;
	void		*player_left2;
	void		*player_right2;
	void		*player_up2;
	void		*player_down2;
	void		*enemy;
}				t_img;

typedef struct s_player
{
	int			y;
	int			x;
	int			on_exit;

}				t_player;

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
	int			exit_x;
	int			exit_y;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;

}				t_map;

void			validate_map(t_map *map);
void			free_array(char **arr, int i);
void			size_error(t_map *map);
void			map_initializer(t_map *map, char **av);
void			check_size(t_map *map);
void			check_player(t_map *map);
void			change_route(int x, int y, t_map *map);
void			check_route(t_map *map);
void			check_param(t_map *map);

void			error_map_elements(t_map *map);
void			file_error(void);
void			wall_error(t_map *map);
void			open_error(void);
void			free_exit_map(t_map *map);
void			create_map_array(t_map *map);
char			*ft_strjoin_freed(char *s1, char *s2);
void			file_to_image(t_map *map);

void			key_hook_func(mlx_key_data_t keydata, void *param);
void			map_printer(t_map *map);
void			move_up(t_map *map);
void			move_left(t_map *map);
void			move_right(t_map *map);
void			move_down(t_map *map);
int				close_game(t_map *map);
void			move_resume(t_map *map, int x, int y, int direction);
void			print_moves(t_map *map);
void			exit_map(t_map *map);
void			file_to_image_player(t_map *map);
void			free_images(t_map *map);
#endif