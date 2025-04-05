/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:08:56 by aleortiz          #+#    #+#             */
/*   Updated: 2025/04/04 14:30:26 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	sub_len;
	char	*s2;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start >= len_s)
		return (ft_strdup(""));
	sub_len = len;
	if (start + sub_len > len_s)
		sub_len = len_s - start;
	s2 = (char *)malloc((sub_len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s + start, sub_len + 1);
	s2[sub_len] = '\0';
	return (s2);
}
