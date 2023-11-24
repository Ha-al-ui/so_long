/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:51 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:51 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		win_width;
	int		win_height;
	int		img_wid;
	int		img_hei;
	void	*img_wall;
	void	*img_player;
	void	*img_floor;
	void	*img_exit;
	void	*img_collect;
	int		x_player;
	int		y_player;
	int		move;
	int		over;
	int		x_exit;
	int		y_exit;

}	t_game;

int		map_check(t_game *game);
char	**read_map(char *file);
int		player_check(t_game *game);
int		collect_check(t_game *game);
int		exit_check(t_game *game);
void	ft_putstr(char *s);
void	ft_error(char *str);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, int len);
int		drw_map(t_game	*game);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
void	init_game(t_game *game);
int		mouve(int keycode, void *vars);
int		close_game(t_game *game);
void	key_w(t_game *game);
void	key_d(t_game *game);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	updt_plyr_img(t_game *game, int keycode);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		path_valid(t_game *game, char *map_path);
void	free_map(char **map);
int		height_of_map(char	**map);
int		width_of_map(char **map);
int		width_of_map(char	**map);
#endif
