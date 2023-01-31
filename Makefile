# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 14:59:41 by ymehlil           #+#    #+#              #
#    Updated: 2023/01/30 14:32:39 by ymehlil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= so_long.c utils.c check_map.c fill_data.c way.c display.c handle.c

SRCSD	= srcs/

OBJSD	= objs/

GNL_PATH	= get_next_line/
GNL_SRCS	= get_next_line.c get_next_line_utils.c
GNL_OBJS	= $(addprefix $(OBJSD), $(GNL_SRCS:.c=.o))
OBJS 	= $(addprefix $(OBJSD), $(SRCS:.c=.o))

LIBFT_A	= libft/libft.a
MLX_A = minilibx-linux/libmlx_Linux.a
PRINTF_A = ft_printf/libftprintf.a

CC = cc -c -o
LINKER = cc -o 
FLAGS = -Wall -Wextra -Werror
 
all: $(NAME)
	
$(LIBFT_A):
	make -C libft
	
$(PRINTF_A):
	make -C ft_printf

$(MLX_A):
	make -C minilibx-linux

$(NAME): $(OBJS) $(PRINTF_A) $(GNL_OBJS) $(LIBFT_A) $(MLX_A) 
	$(LINKER) $@ $^ -lX11 -lXext

$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $^ $(FLAGS)

$(OBJSD)%.o: $(GNL_PATH)%.c
	$(CC) $@ $< $(FLAGS)

clean:
	rm -rf $(OBJSD)
	make -C libft clean
	make -C ft_printf clean
	make -C minilibx-linux clean

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
