# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleortiz <aleortiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 16:33:40 by aleortiz          #+#    #+#              #
#    Updated: 2025/04/04 14:37:22 by aleortiz         ###   ########.fr        #
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
HEADERS = ./header
SRC = ./src
UTILS = ./Utils
MLX = ./MLX42
MAPS = ./maps
RMDIR = ./obj
#=======================================#

# nombres y dependencias #
MYPROG = so_long
MLX42MA= $(MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIB42 = $(UTILS)/libft.a
#=======================================#

# Archivos fuente y crear objetos   ====================#
FILES = $(addprefix $(SRC)/,main.c\
							Utilities.c\
							Utilities_2.c\
							load_images.c\
							first_cheking.c\
							key_buildings.c\
							error_check_free.c\
							read_and_checkmap.c)
OBJS = $(addprefix $(RMDIR)/, $(notdir $(FILES:.c=.o)))
#=======================================================#

# Compiladores y flags    ==========================================================#
CC = cc
LIBCC = ar rcs
CFLAGS = -Wall -Werror -Wextra -g -Wunreachable-code -Ofast
INCFLAGS = -I$(HEADERS)
SANIT = -fsanitize=address,undefined
#===================================================================================#

all:$(MYPROG)

LIB:
	@make -sC $(UTILS)

LIBMLX:
	@cmake  $(MLX) -B $(MLX)/build && make -sC $(MLX)/build -j4
	@echo "$(GREEN)----------------Lib utils done-------------------$(RESET)"

$(RMDIR) :
	@mkdir -p $(RMDIR)

$(RMDIR)/%.o : $(SRC)/%.c | $(RMDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $< to $@$(RESET)"

$(MYPROG) : LIBMLX LIB $(OBJS)
	@$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIB42) $(MLX42MA) -o$(MYPROG)

clean :
	@make clean -sC $(UTILS)
	@rm -rf $(RMDIR)

fclean : clean
	@make fclean -s -C $(UTILS)
	@rm -fr $(MYPROG)
	@rm -fr $(MLX)/build

re : fclean all

.PHONY: all clean fclean run re
