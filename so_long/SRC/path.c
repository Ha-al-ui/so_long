/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:23:17 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/23 04:06:01 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	cords_p(t_game *game)
{
	int	i;
	int	j; 

	i = -1;
	j = 0;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->y_player = i;
				game->x_player = j;
			}
		}
	}
}

int	check_e(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'X')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_c(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	if (count == 0)
		return (0);
	return (1);
}

void	findpath(int x, int y, char **map)
{
	if (map[y][x] == 'E')
		map[y][x] = 'X';
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = '1';
	findpath(x + 1, y, map);
	findpath(x, y + 1, map);
	findpath(x - 1, y, map);
	findpath(x, y - 1, map);
	return ;
}

int	path_valid(t_game *game, char *map_path)
{
	char	**map;

	map = read_map(map_path);
	cords_p(game);
	findpath(game->x_player, game->y_player, map);
	if (check_e(map) == 1)
	{
		ft_error("ERROR\nthe player can't go to exit");
		free_map(map);
		return (0);
	}
	if (check_c(map) == 1)
	{
		ft_error("ERROR\nthe player can't collect all the collecters");
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
