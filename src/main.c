/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:46 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:27:22 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	init_data(t_map *map);

int	main(int argc, char *argv[])
{
	t_map	map;

	init_data(&map);
	if (check_arg(argc, argv))
		exit(1);
	if (charge_check_map(argv[1], &map))
		exit(1);
	
}

static void	init_data(t_map *map)
{
	map->y_max = 0;
	map->x_max = 0;
	map->player = 0;
	map->exit = 0;
	map->collect = 0;
	map->x_player = 0;
	map->y_player = 0;
	map->unech = 0;
	map->error = FALSE;
}
