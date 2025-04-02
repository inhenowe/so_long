/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:15:02 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/01 19:27:07 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	copy_matrix(char **dest, char **src, int y, int x)
{
	int i;

	i = -1;
	while (++i < y)
	{
		dest[i] = malloc(sizeof(char) * x - 1);
		if (!dest[i])
		{
			free_pointer(dest);
			return ;
		}
		ft_memmove(dest[i], src[i], x);
	}
	dest[y] = NULL;
}