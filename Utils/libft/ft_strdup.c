/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:21:31 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/31 14:47:37 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../Inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	if (s == NULL)
		return (NULL);
	dest = malloc (ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, ft_strlen(s)+1);
	return (dest);
}
