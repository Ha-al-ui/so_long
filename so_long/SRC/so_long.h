#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct s_game
{
	void	*mlx;
	char	**map;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		win_width;
	int		win_height;
	int		img_wid;
	int		img_hei;
}	t_game;

int 	map_check(t_game *game);
char    **read_map(char *file);
int 	player_check(t_game *game);
int 	collect_check(t_game *game)
int 	exit_check(t_game *game);
void	ft_putstr(char *s);
void	ft_error(char *str);
int	    ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

#endif