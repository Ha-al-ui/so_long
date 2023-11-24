/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:44 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/23 09:00:27 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_drw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

static	void	ply_drw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

static	void	ext_drw(t_game *game, void *image, int x, int y)
{
	if (game->n_collect == 0)
	{
		image = mlx_xpm_file_to_image(game->mlx,
				"./textures/exit_2.xpm", &game->img_wid, &game->img_hei);
		if (!game->img_exit)
		{
			ft_error("Error\nimage problem");
			exit(1);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}

int	drw_map(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_drw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_drw(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'C')
				img_drw(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
				ext_drw(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'P')
				ply_drw(game, game->img_player, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
