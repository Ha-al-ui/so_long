/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:43 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:43 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static  int height_of_map(char **map)
{
    int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int rectangular_check(char **map)
{
    int i;

    i = 1;
    if (!map)
        return (0);
    while (map[i])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[0]))
        {
            ft_error("Error: Map must be rectangular\n");
            return (0);
        }
        i++;
    }
    return (1);
}

static int wall_check(char **map)
{
    int	j;
	int	c;

	j = -1;
	c = height_of_map(map);
	while (++j < ft_strlen(map[0]))
		if (map[0][j] != '1')
            return (0);
	j = -1;
	while (++j < ft_strlen(map[c - 1]))
		if (map[c - 1][j] != '1')
            return (0);
	j = -1;
	while (++j < c)
		if (map[j][ft_strlen(map[j]) - 1] != '1' || map[j][0] != '1')
            return (0);
	return (1);
}

int map_check(t_game *game)
{
   if (wall_check(game->map) && rectangular_check(game->map) 
    && player_check(game) && collect_check(game) && exit_check(game))
       return (1);
   else
   {
       ft_error("Error: Invalid map\n");
       return (0);
   }
}