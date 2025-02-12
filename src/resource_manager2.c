/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_manager2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:55:40 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 22:14:54 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images1(t_map *map)
{
	if (map->img.player_left1)
	{
		mlx_delete_image(map->mlx, map->img.player_left1);
		map->img.player_left1 = NULL;
	}
	if (map->img.player_right1)
	{
		mlx_delete_image(map->mlx, map->img.player_right1);
		map->img.player_right1 = NULL;
	}
	if (map->img.player_up1)
	{
		mlx_delete_image(map->mlx, map->img.player_up1);
		map->img.player_up1 = NULL;
	}
	if (map->img.player_down1)
	{
		mlx_delete_image(map->mlx, map->img.player_down1);
		map->img.player_down1 = NULL;
	}
}

void	free_images2(t_map *map)
{
	if (map->img.player_down_basic1)
	{
		mlx_delete_image(map->mlx, map->img.player_down_basic1);
		map->img.player_down_basic1 = NULL;
	}
	if (map->img.empty)
	{
		mlx_delete_image(map->mlx, map->img.empty);
		map->img.empty = NULL;
	}
	if (map->img.wall)
	{
		mlx_delete_image(map->mlx, map->img.wall);
		map->img.wall = NULL;
	}
	if (map->img.exit)
	{
		mlx_delete_image(map->mlx, map->img.exit);
		map->img.exit = NULL;
	}
}

void	free_images3(t_map *map)
{
	if (map->img.exit_open)
	{
		mlx_delete_image(map->mlx, map->img.exit_open);
		map->img.exit_open = NULL;
	}
	if (map->img.collectible)
	{
		mlx_delete_image(map->mlx, map->img.collectible);
		map->img.collectible = NULL;
	}
}

void	free_images(t_map *map)
{
	if (!map || !map->mlx)
		return ;
	free_images1(map);
	free_images2(map);
	free_images3(map);
}

void	file_to_image(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/textures/map/empty.png");
	map->img.empty = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/wall.png");
	map->img.wall = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/exit_closed.png");
	map->img.exit = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/exit_open.png");
	map->img.exit_open = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/collectible.png");
	map->img.collectible = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	file_to_image_player(map);
}
