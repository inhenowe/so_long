/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:23:28 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/31 14:46:21 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/libft.h"

int	ft_strlen(const char *str)
{
	int	ctu_str;

	ctu_str = 0;
	if (str == NULL)
		return (0);
	while (str[ctu_str] != 0)
		ctu_str++;
	return (ctu_str);
}
