# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 13:06:29 by aleortiz          #+#    #+#              #
#    Updated: 2025/04/01 14:06:06 by aleortiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables de color  #
RESET = \033[0m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
#=====================#

# Caminos a cabeceras y archivos fuente #
HEADERS = ./Inc
LIBSRC = ./libft
GETSRC = ./get_next_line
PRINTSRC = ./printf
#=======================================#

# Archivos fuente y crear objetos   ====================#
FILES = $(addprefix $(LIBSRC)/, ft_atoi.c \
								ft_bzero.c\
								ft_isalnum.c\
								ft_isalpha.c\
								ft_isascii.c\
								ft_isdigit.c\
								ft_isprint.c\
								ft_memcmp.c\
								ft_memcpy.c\
								ft_memset.c\
								ft_strchr.c\
								ft_strrchr.c\
								ft_strlcat.c\
								ft_strlen.c\
								ft_strncmp.c\
								ft_strrchr.c\
								ft_tolower.c\
								ft_toupper.c\
								ft_memmove.c\
								ft_calloc.c\
								ft_strdup.c\
								ft_strlcpy.c\
								ft_memchr.c\
								ft_strnstr.c\
								ft_substr.c\
								ft_strjoin.c\
								ft_strtrim.c\
								ft_split.c\
								ft_itoa.c\
								ft_strmapi.c\
								ft_striteri.c\
								ft_putchar_fd.c\
								ft_putstr_fd.c\
								ft_putendl_fd.c\
								ft_putnbr_fd.c)\
		$(addprefix $(GETSRC)/, get_next_line.c)\
		$(addprefix $(PRINTSRC)/,ft_printf.c\
								ft_print_str.c\
								ft_print_hexa.c\
								ft_print_decimal.c\
								ft_print_unsigned.c\
								ft_print_pointer.c)
OBJS=$(FILES:.c=.o)
#=======================================================#

# Crear el .a  =======================#
NAME = libft.a
#=====================================#

# Compiladores y flags    ==========================================================#
CC = cc
LIBCC = ar rcs
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I$(HEADERS)
#===================================================================================#

all: $(NAME)

%.o : %.c 
	@$(CC) $(CFLAGS) -I ./Inc -c $< -o $@
	@echo "$(YELLOW)compling $< to $@$(RESET)"

$(NAME) : $(OBJS)
	@$(LIBCC) $(NAME) $(OBJS)
	@echo "$(GREEN)----------------Lib utils done-------------------$(RESET)"

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean 
