/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:48:55 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/10 22:48:55 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (i == 0 || j == 0 || i == ft_strlen(map) - 1 || j == ft_strlen(map[i]) - 1)
            {
                if (map[i][j] != '1')
                {
                    ft_error("Error: Map must be surrounded by walls\n");
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

int map_check(t_game *game)
{
   if (rectangular_check(game->map) && wall_check(game->map) && player_check(game) && colect_check(game) && exit_check(game))
       return (1);
   else
   {
       ft_error("Error: Invalid map\n");
       return (0);
   }
}