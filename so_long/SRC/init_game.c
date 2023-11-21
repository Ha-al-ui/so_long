/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:41 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:41 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_img(t_game *game)
{
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "./IMG/wall.xpm", &game->img_wid, &game->img_hei);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "./IMG/player.xpm", &game->img_wid, &game->img_hei);
    game->img_collect = mlx_xpm_file_to_image(game->mlx, "./IMG/collect.xpm", &game->img_wid, &game->img_hei);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "./IMG/exit_1.xpm", &game->img_wid, &game->img_hei);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "./IMG/floor.xpm", &game->img_wid, &game->img_hei);
    if (!game->img_collect || !game->img_exit || !game->img_floor || !game->img_player || !game->img_wall)
    {
        ft_error("Error : image problem");
        exit(1);
    }
}

static  void    win_size(t_game *game)
{
    int i;

    game->win_width = ft_strlen(game->map[0]) * 64;
    i = 0;
    while (game->map[i])
        i++;
    game->win_height = i * 64;
}

void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    win_size(game);
    game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "so_long");
    game->move = 0;
    game->over = 0;
    init_img(game);
    drw_map(game);
}