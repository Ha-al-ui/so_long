#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../LIBRARY/libft/libft.h"
# include "../LIBRARY/libft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		result;
	int		endgame;
}	t_game;

int map_check(t_game *game);
char    **read_map(char *file);
int player_check(t_game *game);
int collect_check(t_game *game)
int exit_check(t_game *game);

#endif