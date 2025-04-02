/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:25:47 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/26 18:58:40 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	ctu_i;
	size_t	ctu_f;
	char	*s2;

	s2 = 0;
	if (s1 != 0 && set != 0)
	{
		ctu_i = 0;
		ctu_f = ft_strlen(s1);
		while (s1[ctu_i] && ft_strchr(set, s1[ctu_i]))
			ctu_i++;
		while (s1[ctu_f - 1] && ft_strchr(set, s1[ctu_f -1]) && ctu_f > ctu_i)
			ctu_f--;
		s2 = (char *)malloc(sizeof(char) * (ctu_f - ctu_i + 1));
		if (s2)
			ft_strlcpy(s2, &s1[ctu_i], ctu_f - ctu_i + 1);
	}
	return (s2);
}
