/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:11:44 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:27:08 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_error_log(t_map *map)
{
	if (map->player < 1)
	{
		map->error = TRUE;
		ft_putendl_fd(M3P1, 2);
	}
	if (map->player > 1)
	{
		map->error = TRUE;
		ft_putendl_fd(M3P2, 2);
	}
	if (map->exit != 1)
	{
		map->error = TRUE;
		ft_putendl_fd(M3E1, 2);
	}
	if (map->collect < 1)
	{
		map->error = TRUE;
		ft_putendl_fd(M3C1, 2);
	}
	if (map->unech != 0)
	{
		map->error = TRUE;
		ft_putendl_fd(M3U1, 2);
	}
}

static void	floodfill(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x])
	{
		map[y][x] = '1';
		floodfill(map, x + 1, y);
		floodfill(map, x - 1, y);
		floodfill(map, x, y + 1);
		floodfill(map, x, y - 1);
	}
}

static void	is_winnable(char **prove, t_map *map)
{
	int	i;
	int	j;
	
	i = -1;
	j = 0;
	while (prove[++i])
	{
		j = -1;
		while (prove[i][++j])
		{
			if (prove[i][j] == 'E')
				map->error = TRUE;
			if (prove[i][j] == 'C')
				map->error = TRUE;
		}
	}
	free_pointer(prove);
}
void	is_close(t_map *map, int i, int j)
{
	while (++j < map->x_max - 1 && map->map[0][j])
		if (map->map[0][j] != '1' || map->map[map->y_max - 1][j] != '1')
			map->error = TRUE;
	while (++i <= map->y_max - 1 && map->map[i])
		if (map->map[i][0] != '1' || map->map[i][map->x_max - 2] != '1')
			map->error = TRUE;
}

void	alord(t_map *map)
{
	int		i;
	int		j;
	char	**cmap;

	j = -1;
	i = -1;
	cmap = malloc(sizeof(char **) * map->y_max + 1);
	map->error = FALSE;
	if (!cmap)
		return ;
	copy_matrix(cmap, map->map, map->y_max, map->x_max);
	is_close(map, i, j);
	if (map->error == TRUE)
	{
		ft_putendl_fd(M3, 2);
		return ;
	}
	else
		floodfill(cmap, map->x_player, map->y_player);
	is_winnable(cmap, map);
	if (map->error == TRUE)
	{
		ft_putendl_fd(M3, 2);
		return ;
	}
}
