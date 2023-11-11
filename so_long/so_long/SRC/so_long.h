/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:49:04 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/10 22:49:04 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../LIBRARY/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	char	**map;
	int		n_colect;
	int		n_player;
	int		n_exit;
}	t_game;

int map_check(t_game *game);
char    **read_map(char *file);
int player_check(t_game *game);
int collect_check(t_game *game);
int exit_check(t_game *game);

#endif