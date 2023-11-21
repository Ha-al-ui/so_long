/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:19:32 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/21 02:24:32 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mouve(int keycode, void *vars)
{
    t_game *game = vars;
    mlx_clear_window(game->mlx, game->win);
    if (keycode == 53)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    
    if (keycode == 13 || keycode == 126)
    {
        if (game->map[game->y_player - 1][game->x_player] != '1')
        {
            if (game->map[game->y_player - 1][game->x_player] == 'C')
            {
                game->n_collect--;
                game->map[game->y_player - 1][game->x_player] = '0';
            }
            game->map[game->y_player][game->x_player] = '0';
            game->map[game->y_player - 1][game->x_player] = 'P';
        }
        
    }
    else if (keycode == 2 || keycode == 124)
    {
        if (game->map[game->y_player][game->x_player + 1] != '1')
        {
            if (game->map[game->y_player][game->x_player + 1] == 'C')
                {
                game->n_collect--;
                game->map[game->y_player][game->x_player + 1] = '0';
            }
            game->map[game->y_player][game->x_player] = '0';
            game->map[game->y_player][game->x_player + 1] = 'P';
        }
    }
    else if (keycode == 0 || keycode == 123)
    {
        if (game->map[game->y_player][game->x_player - 1] != '1')
        {
            if (game->map[game->y_player][game->x_player - 1] == 'C')
                {
                game->n_collect--;
                game->map[game->y_player][game->x_player - 1] = '0';
            }
            game->map[game->y_player][game->x_player] = '0';
            game->map[game->y_player][game->x_player - 1] = 'P';
        }
    }
    else if (keycode == 1 || keycode == 125)
    {
        if (game->map[game->y_player + 1][game->x_player] != '1')
        {
            if (game->map[game->y_player + 1][game->x_player] == 'C')
                {
                game->n_collect--;
                game->map[game->y_player + 1][game->x_player] = '0';
            }
            game->map[game->y_player][game->x_player] = '0';
            game->map[game->y_player + 1][game->x_player] = 'P';
        }
    }
    game->move++;
    printf("%d\n",game->move);
    drw_map(game);
    return (0);
}