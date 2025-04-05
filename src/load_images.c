/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:43 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/04 19:21:20 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_bool	load_tex(t_map *map)
{
	map->texture = malloc(sizeof(t_texture));
	if (!(map->texture->rock = mlx_load_png(TEXR)))
		return (TRUE);
	if (!(map->texture->exit = mlx_load_png(TEXE)))
		return (TRUE);
	if (!(map->texture->ply = mlx_load_png(TEXP)))
		return (TRUE);
	if (!(map->texture->floor = mlx_load_png(TEXF)))
		return (TRUE);
	if (!(map->texture->cllt = mlx_load_png(TEXC)))
		return (TRUE);
	return (FALSE);
}

t_bool	load_img(t_map *map)
{
	map->images= malloc(sizeof(t_images));
	map->images->rock = mlx_texture_to_image(map->mlx, map->texture->rock);
	if (!map->images->rock)
		return (TRUE);
	map->images->exit = mlx_texture_to_image(map->mlx, map->texture->exit);
	if (!map->images->exit)
		return (TRUE);
	map->images->ply = mlx_texture_to_image(map->mlx, map->texture->ply);
	if (!map->images->ply)
		return (TRUE);
	map->images->floor = mlx_texture_to_image(map->mlx, map->texture->floor);
	if (!map->images->floor)
		return (TRUE);
	map->images->cllt = mlx_texture_to_image(map->mlx, map->texture->cllt);
	if (!map->images->cllt)
		return (TRUE);
	return (FALSE);
}

void	reload(t_map *map)
{
	mlx_delete_image(map->mlx, map->images->rock);
	mlx_delete_image(map->mlx, map->images->exit);
	mlx_delete_image(map->mlx, map->images->ply);
	mlx_delete_image(map->mlx, map->images->floor);
	mlx_delete_image(map->mlx, map->images->cllt);
	free(map->images);
	load_img(map);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;
	
	i = -1;
	j = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			mlx_image_to_window(map->mlx, map->images->floor, j*64, i*64);
			if (map->map[i][j] == 'E')
				mlx_image_to_window(map->mlx, map->images->exit, j*64, i*64);
			if (map->map[i][j] == 'C')
				mlx_image_to_window(map->mlx, map->images->cllt, j*64, i*64);
			if (map->map[i][j] == '1')
				mlx_image_to_window(map->mlx, map->images->rock, j*64, i*64);
		}
	}
	mlx_image_to_window(map->mlx, map->images->ply, map->x_player*64, map->y_player*64);
}
