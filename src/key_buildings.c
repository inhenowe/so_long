/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_buildings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:40 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/04 13:46:01 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	key_w(t_map *map)
{
	if(map->map[map->y_player - 1][map->x_player] != '1')
	{
		if (map->map[map->y_player - 1][map->x_player] == 'C')
		{
			map->map[map->y_player - 1][map->x_player] = '0';
			map->collect--;
		}
		if (map->map[map->y_player - 1][map->x_player] == 'E' &&\
			map->collect == 0)
			exitw(map);
		map->y_player -= 1;
		ft_printf("moves:%d\n", map->moves++);
		reload(map);
		draw_map(map);
	}
}

void	key_s(t_map *map)
{
	if(map->map[map->y_player + 1][map->x_player] != '1')
	{
		if (map->map[map->y_player + 1][map->x_player] == 'C')
		{
			map->map[map->y_player + 1][map->x_player] = '0';
			map->collect--;
		}
		if (map->map[map->y_player + 1][map->x_player] == 'E' &&\
			map->collect == 0)
			exitw(map);
		map->y_player += 1;
		ft_printf("moves:%d\n", map->moves++);
		reload(map);
		draw_map(map);
	}
}

void	key_a(t_map *map)
{
	if(map->map[map->y_player][map->x_player - 1] != '1')
	{
		if (map->map[map->y_player][map->x_player - 1] == 'C')
		{
			map->map[map->y_player][map->x_player - 1] = '0';
			map->collect--;
		}
		if (map->map[map->y_player][map->x_player - 1] == 'E' &&\
			map->collect == 0)
			exitw(map);
		map->x_player -= 1;
		ft_printf("moves:%d\n", map->moves++);
		reload(map);
		draw_map(map);
	}
}

void	key_d(t_map *map)
{
	if(map->map[map->y_player][map->x_player + 1]  != '1')
	{
		if (map->map[map->y_player][map->x_player + 1] == 'C')
		{
			map->map[map->y_player][map->x_player + 1] = '0';
			map->collect--;
		}
		if (map->map[map->y_player][map->x_player + 1] == 'E' &&\
			map->collect == 0)
			exitw(map);
		map->x_player += 1;
		ft_printf("moves:%d\n", map->moves++);
		reload(map);
		draw_map(map);
	}
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		key_w(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		key_s(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		key_a(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		key_d(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exitw(param);
}