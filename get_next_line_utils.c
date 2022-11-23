/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:46:50 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/23 18:08:56 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*array;
	int		i;

	array = (char *)str;
	i = 0;
	while (*array != (unsigned char)c && *array != '\0')
	{
		array++;
	}
	if (*array == (unsigned char)c)
		return (array);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (s1 == '\0' || s2 == '\0')
		return (0);
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((void*)s1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	space;

	if (s == '\0')
		return (0);
	i = start;
	space = start;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (start >= ft_strlen(s))
	{
		*s2 = '\0';
		return (s2);
	}
	if (s2 == '\0')
		return (0);
	while (s[i] != '\0' && i < len + space)
		s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}

char	*ft_strdup_v2(const char *src, size_t dstsize)
{
	size_t		i;
	char	*dest;

	dest = malloc(sizeof(char) * (dstsize + 1));
	i = 0;
	if (dest == '\0')
		return (0);
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
		dest[i + 1] = '\0';
	if(src[i] == '\0')
		dest[i] = '\0'; 
	return (dest);
}
