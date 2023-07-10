# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:59:07 by ratavare          #+#    #+#              #
#    Updated: 2023/03/24 11:12:04 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

INCLUDES	=	-I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g  -O3 -march=native -ffast-math -funsafe-math-optimizations -ffinite-math-only -o2
RM		=	rm -f

HEADERS_LIST = fdf.h\

HEADERS_DIRECTORY = ./includes/

LIBFT	=	./libft/libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

MLX_FLAGS	=	-Lmlx_linux -lXext -lX11 -lm -lz
MLX_LIB		=	minilibx/libmlx.a
MLX_DIRECTORY = ./minilibx/

SRC		=	srcs/*.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all:			$(NAME)

$(NAME):		$(LIBFT) $(SRC) $(MLX_LIB)
				$(CC) $(CFLAGS) $(SRC) -O3 $(MLX_LIB) $(LIBFT) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
				make -C ./libft
$(MLX_LIB):
				make -C ./minilibx

clean:			
				make clean -C ./libft
				make clean -C ./minilibx
				$(RM) $(OBJ) $(BOBJ)

fclean: clean
				make clean -C ./libft
				make clean -C ./minilibx
				$(RM) $(NAME)

re:		fclean	$(NAME)