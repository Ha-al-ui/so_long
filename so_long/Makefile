# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 09:46:54 by halaoui           #+#    #+#              #
#    Updated: 2023/11/23 09:46:54 by halaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC 			=	cc

CFLAGS		=	-Wall -Werror -Wextra

MLX			=	-lmlx -framework OpenGL -framework AppKit

SRC_M		=	SRC/so_long.c\
				SRC/map_check.c\
				SRC/cep.c\
				SRC/read_map.c\
				SRC/drw_map.c\
				SRC/init_game.c\
				SRC/move_ment.c\
				SRC/key_bord.c\
				SRC/close_game.c\
				SRC/path.c\
				libft/ft_error.c\
				libft/ft_strlen.c\
				libft/ft_strjoin.c\
				libft/ft_putstr.c\
				libft/ft_split.c\
				libft/ft_strdup.c\
				libft/ft_substr.c\
				libft/get_next_line.c\
				libft/ft_putnbr.c\
				libft/ft_putchar.c\

OBJS		=	$(SRC_M:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(MLX) -o $(NAME)

%o: %c so_long.h
	$(CC) $(CFLAGS) -c $<

clean		:
				@rm -f $(OBJS)

fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus