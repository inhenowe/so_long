/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:11:14 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/26 18:57:44 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/libft.h"

char	*ft_strchr(char *str, int c)
{
	size_t	ctu_str;

	ctu_str = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[ctu_str] != (char)c && str[ctu_str] != 0)
		ctu_str++;
	if (str[ctu_str] == (char)c)
		return (&str[ctu_str]);
	return (0);
}
