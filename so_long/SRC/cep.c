/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:37 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:37 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_check(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'P')
                game->n_player++;
        }
    }
    if (game->n_player != 1)
        return (0);
    return (1);
}

int collect_check(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'C')
                game->n_collect++;
        }
    }
    if (game->n_collect == 0)
        return (0);
    return (1);
}

int exit_check(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'E')
                game->n_exit++;
        }
    }
    if (game->n_exit != 1)
        return (0);
    return (1);
}