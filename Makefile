# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:57:42 by bbekmama          #+#    #+#              #
#    Updated: 2020/01/16 12:35:47 by bbekmama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WWW = -Wall -Werror -Wextra
SRC = *.c
NAM = fdf
LIB = libft/libft.a
MLX = minilibx_macos/libmlx.a
FRM	= -framework OpenGL -framework Appkit libft/libft.a
OBJ = $(SRC:.c=.o)

all:
	make -C libft
	make -C minilibx_macos
	gcc $(WWW) $(SRC) -o $(NAM) $(MLX) $(FRM)
	echo "Compilation is successful"
clean:
	-rm -f $(OBJ)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all