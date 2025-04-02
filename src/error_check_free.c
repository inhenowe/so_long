/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:28:37 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/31 19:02:55 by aleortiz         ###   ########.fr       */
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
	spl = NULL;
}
