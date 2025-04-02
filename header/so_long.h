/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:30 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:28:25 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Utils/Inc/ft_printf.h"
# include "../Utils/Inc/get_next_line.h"
# include "../Utils/Inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define M0 "ERROR\nNumbers of arguments wrong"
# define M1 "ERROR\nThe file or directory not exist"
# define M2 "ERROR\nThe file type is not valid. Remember that the file must be\
 <example.ber>"
# define M3 "ERROR\nInvalid map my friend"
# define M3P1 "ERROR\nWhithout player you can't play :("
# define M3P2 "ERROR\nIs not a cooperative game"
# define M3E1 "ERROR\nProblems with exit"
# define M3C1 "ERROR\nNo objetives, boring game"
# define M3U1 "ERROR\nUnexpected character reading the map"


typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_map
{
	char	**map;
	int		y_max;
	int		x_max;
	int		player;
	int		x_player;
	int		y_player;
	int		collect;
	int		exit;
	int		unech;
	t_bool	error;
}			t_map;

t_bool	check_arg(int argc, char *argv[]);
t_bool	charge_check_map(char *path_map, t_map *map);
void	map_error_log(t_map *map);
void	alord(t_map *map);
void	free_pointer(char **spl);
void	copy_matrix(char **dest, char **src, int y, int x);

#endif