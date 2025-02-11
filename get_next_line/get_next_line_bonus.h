/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:37:01 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 12:22:54 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42   
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


char	*get_next_line(int fd);
char	*ft_strdup_2(const char *s);
size_t	ft_strlen_2(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin_2(const char *s1, const char *s2);
void	fill_str(char *res, char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif