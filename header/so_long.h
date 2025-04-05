/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:30 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/04 13:28:04 by aleortiz         ###   ########.fr       */
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
# define TEXR "/home/aleortiz/Desktop/PR/primeros_proyectos/so_long/assets/rock.png"
# define TEXP "/home/aleortiz/Desktop/PR/primeros_proyectos/so_long/assets/player.png"
# define TEXF "/home/aleortiz/Desktop/PR/primeros_proyectos/so_long/assets/floor.png"
# define TEXC "/home/aleortiz/Desktop/PR/primeros_proyectos/so_long/assets/collect.png"
# define TEXE "/home/aleortiz/Desktop/PR/primeros_proyectos/so_long/assets/exit.png"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*ply;
	mlx_texture_t	*cllt;
	mlx_texture_t	*exit;
	mlx_texture_t	*rock;
}	t_texture;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*ply;
	mlx_image_t	*cllt;
	mlx_image_t	*exit;
	mlx_image_t	*rock;
}	t_images;

typedef struct s_map
{
	char		**map;
	int			y_max;
	int			x_max;
	int			player;
	int			x_player;
	int			y_player;
	int			collect;
	int			exit;
	int			unech;
	int			moves;
	mlx_t		*mlx;
	t_texture	*texture;
	t_images	*images;
	t_bool		error;
}	t_map;

t_bool	check_arg(int argc, char *argv[]);
t_bool	charge_check_map(char *path_map, t_map *map);
void	map_error_log(t_map *map);
void	alord(t_map *map);
void	free_pointer(char **spl);
void	copy_matrix(char **dest, char **src, int y, int x);
t_bool	load_tex(t_map *map);
t_bool	load_img(t_map *map);
void	reload(t_map *map);
void	exitw(t_map *map);
void	draw_map(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void* param);

#endif