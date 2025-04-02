/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:35:10 by aleortiz          #+#    #+#             */
/*   Updated: 2025/03/31 19:07:15 by aleortiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	print_str(char *str);
int	print_char(int c);
int	ft_print_decimal(int n);
int	ft_print_unsigned(unsigned int nb);
int	print_hexa_mini(unsigned long long nb);
int	print_hexa_maxi(unsigned long long mb);
int	print_pointer(void *ptr);

#endif
