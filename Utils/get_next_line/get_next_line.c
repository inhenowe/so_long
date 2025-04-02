/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:11:59 by aleortiz          #+#    #+#             */
/*   Updated: 2025/02/03 16:04:51 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/get_next_line.h"

static char	*from_file_to_str(int fd, char *str);
static char	*copy_line(char *str);
static char	*memory_saved(char *str);

char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free (str);
		return (NULL);
	}
	str = from_file_to_str(fd, str);
	if (!str)
		return (NULL);
	out = copy_line(str);
	str = memory_saved(str);
	return (out);
}

static char	*from_file_to_str(int fd, char *str)
{
	char	*buffer;
	ssize_t	length;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	length = 1;
	while (!ft_strchr(str, '\n') && length > 0)
	{
		length = read(fd, buffer, BUFFER_SIZE);
		if (length == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[length] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*copy_line(char *str)
{
	char	*linea;
	size_t	ctu_s;
	size_t	ctu_l;

	ctu_s = 0;
	if (str[ctu_s] == 0)
		return (NULL);
	while (str[ctu_s] && str[ctu_s] != '\n')
		ctu_s++;
	linea = (char *)malloc(sizeof(char) * (ctu_s + 2));
	if (!linea)
		return (NULL);
	ctu_l = 0;
	while (str[ctu_l] && str[ctu_l] != '\n')
	{
		linea[ctu_l] = str[ctu_l];
		ctu_l++;
	}
	if (str[ctu_l] == '\n')
		linea[ctu_l++] = '\n';
	linea[ctu_l] = '\0';
	return (linea);
}

static char	*memory_saved(char *str)
{
	char	*linea;
	size_t	ctu_s;
	size_t	ctu_l;

	ctu_s = 0;
	while (str[ctu_s] && str[ctu_s] != '\n')
		ctu_s++;
	if (!str[ctu_s])
	{
		free(str);
		return (NULL);
	}
	linea = (char *)malloc(sizeof(char) * (ft_strlen(str) - ctu_s));
	if (!linea)
	{
		free(str);
		return (NULL);
	}
	ctu_s++;
	ctu_l = 0;
	while (str[ctu_s])
		linea[ctu_l++] = str[ctu_s++];
	linea[ctu_l] = '\0';
	free(str);
	return (linea);
}
