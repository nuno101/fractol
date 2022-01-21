# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:36:13 by nlouro            #+#    #+#              #
#    Updated: 2022/01/21 10:43:51 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRACTOL = fractol

C_FLAGS = -Wall -Wextra -Werror
MINILIBX_DIR = minilibx_opengl_20191021
#MINILIBX_DIR = minilibx_macos
MINILIBX = libmlx.a
MINILIBX_FLAGS =  -framework OpenGL -framework AppKit 
FT_PRINTF_DIR = ft_printf
FT_PRINTF_OBJ = libftprintf.a

C_FILES = fractol.c	color.c event_handlers.c browse_image.c ft_isdigit.c ft_atoi.c ft_strncmp.c

O_FILES = $(C_FILES:%.c=%.o)

all: $(FRACTOL)

$(FRACTOL): $(O_FILES) $(MINILIBX) $(FT_PRINTF_OBJ)
	gcc $(C_FLAGS) $(O_FILES) $(MINILIBX_DIR)/$(MINILIBX) $(MINILIBX_FLAGS) $(FT_PRINTF_DIR)/$(FT_PRINTF_OBJ) -o $(FRACTOL)

$(O_FILES): $(C_FILES) $(FT_PRINTF_OBJ) 
	gcc -c $(C_FLAGS) $(C_FILES) -I $(MINILIBX_DIR) -I$(FT_PRINTF_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(FT_PRINTF_OBJ):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(O_FILES)
	#make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(FRACTOL)
	#make -C $(MINILIBX_DIR) clean

re: fclean all

