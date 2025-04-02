/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:41:20 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/31 19:07:51 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_espace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int	simbolo;
	int	ctu;
	int	num;

	ctu = 0;
	simbolo = 1;
	num = 0;
	while (ft_espace(str[ctu]))
		ctu++;
	if (str[ctu] == '+' || str[ctu] == '-')
	{
		if (str[ctu] == '-')
			simbolo *= -1;
		ctu++;
	}
	while (str[ctu] >= '0' && str[ctu] <= '9')
	{
		num = num * 10 + (str[ctu] - '0');
		ctu++;
	}
	return (num * simbolo);
}
