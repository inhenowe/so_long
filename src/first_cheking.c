/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cheking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:16:12 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:27:10 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static t_bool	is_not_ber(char *str)
{
	t_bool	is_ber;
	char	*file;

	is_ber = false;
	file = ft_strrchr(str, '/');
	if (!file)
		return (ft_putendl_fd(M2, 2), !is_ber);
	file++;
	if (*file == '.')
		return (ft_putendl_fd(M2, 2), !is_ber);
	while (*file != '.')
		file++;
	if (ft_strncmp(file, ".ber", 4) != 0)
		return (ft_putendl_fd(M2, 2), !is_ber);
	return (is_ber);
}

t_bool	check_arg(int argc, char *argv[])
{
	t_bool	check;
	int		fd;

	check = FALSE;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		return (ft_putendl_fd(M0, 2), !check);
	if (fd == -1 || !argv[1])
		return (close(fd), ft_putendl_fd(M1, 2), !check);
	if (is_not_ber(argv[1]))
		return (!check);
	return (close(fd), check);
}
