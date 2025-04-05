/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:37 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/04 14:22:48 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_pointer(char **spl)
{
	int	itera;

	itera = 0;
	if (spl == NULL || *spl == NULL)
		return ;
	while (spl[itera])
		free(spl[itera++]);
	free(spl);
}

void	exitw(t_map *map)
{
	mlx_delete_texture(map->texture->rock);
	mlx_delete_texture(map->texture->exit);
	mlx_delete_texture(map->texture->ply);
	mlx_delete_texture(map->texture->floor);
	mlx_delete_texture(map->texture->cllt);
	mlx_delete_image(map->mlx, map->images->rock);
	mlx_delete_image(map->mlx, map->images->exit);
	mlx_delete_image(map->mlx, map->images->ply);
	mlx_delete_image(map->mlx, map->images->floor);
	mlx_delete_image(map->mlx, map->images->cllt);
	free(map->images);
	free(map->texture);
	free_pointer(map->map);
	mlx_close_window(map->mlx);
	exit(0);
}
