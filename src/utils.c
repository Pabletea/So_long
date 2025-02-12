/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:32:11 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 19:49:42 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

void	free_exit_map(t_map *map)
{
	if (map->array)
		free(map->array);
	if (map->copy)
		free(map->copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->file);
	exit(EXIT_FAILURE);
}

char	*ft_strjoin_freed(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}

int	close_game(t_map *map)
{
	free_images(map);
	mlx_terminate(map->mlx);
	free_array(map->array, map->y);
	exit(EXIT_SUCCESS);
	return (0);
}

void	print_moves(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements\n", 12);
	free(move);
}
