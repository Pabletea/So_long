/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:36:57 by pabalons          #+#    #+#             */
/*   Updated: 2024/10/17 11:57:21 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Duplica la cacdena de caracteres y devuelv un puntero a la nueva cadena//
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

//Devuelve la en de la cadena//
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

// Devuelve una subcadena de la cadena de entrada 's' que comienza 
//en la posición 'start' y tiene una longitud máxima de 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = 0;
	while (s[sub_len])
		sub_len++;
	if (start >= sub_len)
		return (ft_strdup(""));
	if (len > sub_len - start)
		len = sub_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

//Concatena strings s1 en s2//
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!new_str)
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		new_str[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		new_str[++i] = s2[j];
	new_str[++i] = '\0';
	return (new_str);
}

//Copia  una caadena origen en una dest"""
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size)
	{
		while (*(src + len) && --size)
		{
			*dst++ = *(src + len);
			len++;
		}
		*dst = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
