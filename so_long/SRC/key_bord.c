/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:42:02 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/23 08:59:54 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_game *game)
{
	if (game->map[game->y_player - 1][game->x_player] != '1' 
			&& game->map[game->y_player - 1][game->x_player] != 'E')
	{
		if (game->map[game->y_player - 1][game->x_player] == 'C')
		{
			game->n_collect--;
			game->map[game->y_player - 1][game->x_player] = '0';
		}
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player - 1][game->x_player] = 'P';
	}
	else if (game->n_collect == 0 && 
		game->map[game->y_player - 1][game->x_player] == 'E')
	{
		game->over = 1;
		close_game(game);
	}
}

void	key_d(t_game *game)
{
	if (game->map[game->y_player][game->x_player + 1] != '1' 
			&& game->map[game->y_player][game->x_player + 1] != 'E')
	{
		if (game->map[game->y_player][game->x_player + 1] == 'C')
		{
			game->n_collect--;
			game->map[game->y_player][game->x_player + 1] = '0';
		}
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player][game->x_player + 1] = 'P';
	}
	else if (game->n_collect == 0 && 
		game->map[game->y_player][game->x_player + 1] == 'E')
	{
		game->over = 1;
		close_game(game);
	}
}

void	key_a(t_game *game)
{
	if (game->map[game->y_player][game->x_player - 1] != '1' 
			&& game->map[game->y_player][game->x_player - 1] != 'E')
	{
		if (game->map[game->y_player][game->x_player - 1] == 'C')
		{
			game->n_collect--;
			game->map[game->y_player][game->x_player - 1] = '0';
		}
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player][game->x_player - 1] = 'P';
	}
	else if (game->n_collect == 0 && 
		game->map[game->y_player][game->x_player - 1] == 'E')
	{
		game->over = 1;
		close_game(game);
	}
}

void	key_s(t_game *game)
{
	if (game->map[game->y_player + 1][game->x_player] != '1' 
			&& game->map[game->y_player + 1][game->x_player] != 'E')
	{
		if (game->map[game->y_player + 1][game->x_player] == 'C')
		{
			game->n_collect--;
			game->map[game->y_player + 1][game->x_player] = '0';
		}
		game->map[game->y_player][game->x_player] = '0';
		game->map[game->y_player + 1][game->x_player] = 'P';
	}
	else if (game->n_collect == 0 && 
		game->map[game->y_player + 1][game->x_player] == 'E')
	{
		game->over = 1;
		close_game(game);
	}
}

void	updt_plyr_img(t_game *game, int keycode)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (keycode == 13 || keycode == 126)
		game->img_player = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player_2.xpm", &game->img_wid, &game->img_hei);
	if (keycode == 2 || keycode == 124)
		game->img_player = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player_1.xpm", &game->img_wid, &game->img_hei);
	if (keycode == 0 || keycode == 123)
		game->img_player = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player_3.xpm", &game->img_wid, &game->img_hei);
	if (keycode == 1 || keycode == 125)
		game->img_player = mlx_xpm_file_to_image(game->mlx, 
				"./textures/player.xpm", &game->img_wid, &game->img_hei);
}
