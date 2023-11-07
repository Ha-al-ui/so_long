NAME		=	so_long

SRC_M		=	SRC/so_long.c\
				SRC/map_check.c\
				SRC/check_ber.c\

$(NAME)		:	$(SRC_M) $(LIB) $(GET)
			@cc -Wall -Werror -Wextra $(SRC_P) $(LIB) $(GET) -lmlx -framework OpenGL -framework AppKit -o so_long

$(LIB)		:	LIBRARY/libft
			@$(MAKE) -C LIBRARY/libft/

$(GET)		:	LIBRARY/get_next_line
			@$(MAKE) -C LIBRARY/get_next_line/

all			:	$(NAME)

clean		:

fclean		:	clean

re			:	fclean all

.PHONY		:	all clean fclean re bonus