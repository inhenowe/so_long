/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_checkmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:50 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:27:05 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	compare(char c, t_map *map, int i, int j)
{
	if (c == 'P')
	{
		map->player++;
		map->x_player = j;
		map->y_player = i;
	}
	if (c == 'E')
		map->exit++;
	if (c == 'C')
		map->collect++;
	if (c != 'C' && c != 'E' && c != 'P' && c != '0' && c != '1' && c != '\n')
		map->unech++;
}

static t_bool	charge_map(t_map *map, char *path)
{
	int		i;
	int		fd;
	char	*aux;

	i = 0;
	fd = 0;
	map->map = malloc(sizeof(char **) * map->y_max + 1);
	fd = open(path, O_RDONLY, 777);
	while (i <= map->y_max)
	{
		aux = get_next_line(fd);
		if (aux)
			if ((ft_strlen(aux) != map->x_max))
				return (TRUE);
		map->map[i] = ft_strdup(aux);
		free(aux);
		i++;
	}
	close(fd);
	return (FALSE);
}

static t_bool	readmap(int fd, t_map *map)
{
	t_bool	check;
	char	*line;

	check = FALSE;
	line = get_next_line(fd);
	map->x_max = ft_strlen(line);
	while (line)
	{
		map->y_max++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (check);
}

t_bool	at_least_one(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			compare(map->map[i][j], map, i, j);
	}
	map_error_log(map);
	alord(map);
	return (map->error);
}

t_bool	charge_check_map(char *path_map, t_map *map)
{
	t_bool	check;
	int		fd;

	check = FALSE;
	fd = open(path_map, O_RDONLY, 777);
	if (fd == -1)
		exit(1);
	if (readmap(fd, map))
		return (ft_putendl_fd(M3, 2), !check);
	if (charge_map(map, path_map))
		return (ft_putendl_fd(M3, 2), !check);
	if (at_least_one(map))
		return (!check);
	return (check);
}
