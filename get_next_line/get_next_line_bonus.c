/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:41:53 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/11 11:41:45 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*fill_line(char *line_buff)
{
	char	*lefts;
	ssize_t	i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == '\0')
		return (NULL);
	lefts = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i - 1);
	if (lefts && *lefts == '\0')
	{
		free(lefts);
		lefts = NULL;
	}
	line_buff[i + 1] = '\0';
	return (lefts);
}

static char	*fill_buffer(int fd, char *lefts, char *buff)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!lefts)
			lefts = ft_strdup("");
		temp = lefts;
		lefts = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (lefts);
}

char	*get_next_line(int fd)
{
	static char	*lefts[1024];
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (lefts[fd] != NULL)
		{
			free(lefts[fd]);
		}
		free(buff);
		return (lefts[fd] = NULL, NULL);
	}
	line = fill_buffer(fd, lefts[fd], buff);
	free(buff);
	if (!line)
	{
		free(lefts[fd]);
		return (lefts[fd] = NULL, NULL);
	}
	lefts[fd] = fill_line(line);
	return (line);
}
