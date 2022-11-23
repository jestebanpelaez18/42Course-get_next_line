/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:53:52 by jpelaez-          #+#    #+#             */
/*   Updated: 2022/11/23 18:44:18 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *str)
{
	if(str)
	{
		free(str);
		str = NULL;
	}
}

static char	*read_line(int fd, char *buff, size_t buffersize, char *saved)
{
	int	byte_r;

	byte_r = 1;
	while (!(ft_strchr(saved, '\n')) && byte_r != 0)
	{
		byte_r = read(fd, buff, buffersize);
		if (byte_r == -1)
			return (NULL);
		buff[byte_r] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	if (byte_r == 0 || buff[0] == '\0')
		return (NULL);
	return (saved);
}

static char	*get_line(char *sv)
{
	size_t	i;
	char	*line;

	i = 0;
	while (sv[i] != '\0' && sv[i] != '\n')
		i++;
	if (sv[i] == '\n')
		i++;
	line = ft_strdup_v2(sv, i);
	return (line);
}

static char	*next_line(char *sv)
{
	size_t	i;
	char	*new_saved;

	i = 0;
	while (sv[i] != '\0' && sv[i] != '\n')
		i++;
	if (sv[i] == '\n')
		i++;
	new_saved = ft_substr(sv, i, ft_strlen(sv) - i);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*saved;

	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (buffer == '\0')
		return (0);
	if (!saved)
	{
		saved = malloc(1);
		saved[0] = '\0';
	}
	saved = read_line(fd, buffer, BUFFER_SIZE, saved);
	ft_free(buffer);
	line = get_line(saved);
	saved = next_line(saved);
	return (line);
}


int main(void)
{
	int fd;

	fd = open("text_file.txt",O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return(0);
}