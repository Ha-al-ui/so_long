NAME		=	so_long

CC 			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

MLX			=	-lmlx -framework OpenGL -framework AppKit

SRC_M		=	SRC/so_long.c\
				SRC/map_check.c\
				SRC/check_ber.c\
				libft/ft_error.c\
				libft/ft_strlen.c\
				libft/ft_strjoin.c\
				libft/ft_putstr.c\
				libft/ft_split.c\
				libft/ft_strdup.c\
				libft/ft_substr.c\
				libft/get_next_line.c\

OBJS		=	$(SRC_M:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(MLX) -o $(NAME)

%o: %c so_long.h
	$(CC) $(CFLAGS) -c $< 

clean		:
				@rm -f $(OBJS)

fclean		:	clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus