# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:36:13 by nlouro            #+#    #+#              #
#    Updated: 2022/01/06 17:50:19 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL = fractol

C_FLAGS = -Wall -Wextra -Werror
#MINILIBX_DIR = minilibx_opengl_20191021
MINILIBX_DIR = minilibx_macos
MINILIBX = libmlx.a
MINILIBX_FLAGS =  -framework OpenGL -framework AppKit 

C_FILES = fractol.c

O_FILES = $(C_FILES:%.c=%.o)

all: $(FRACTOL)

$(FRACTOL): $(O_FILES) $(MINILIBX)
	gcc $(C_FLAGS) $(O_FILES) $(MINILIBX_DIR)/$(MINILIBX) $(MINILIBX_FLAGS) -o $(FRACTOL)

$(O_FILES): $(C_FILES) 
	gcc -c $(C_FLAGS) $(C_FILES) -I $(MINILIBX_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	rm -f $(O_FILES)
	#make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(FRACTOL)
	#make -C $(MINILIBX_DIR) clean

re: fclean all

