/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:19:32 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/23 05:48:25 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	keys(int keycode, void *vars)
{
	if (keycode == 13 || keycode == 126)
	{
		key_w(vars);
		updt_plyr_img(vars, keycode);
	}
	else if (keycode == 2 || keycode == 124)
	{
		key_d(vars);
		updt_plyr_img(vars, keycode);
	}
	else if (keycode == 0 || keycode == 123)
	{
		key_a(vars);
		updt_plyr_img(vars, keycode);
	}
	else if (keycode == 1 || keycode == 125)
	{
		key_s(vars);
		updt_plyr_img(vars, keycode);
	}
}

int	mouve(int keycode, void *vars)
{
	t_game	*game;
	int		old_x;
	int		old_y;

	game = vars;
	old_x = game->x_player;
	old_y = game->y_player;
	if (keycode == 53)
		close_game(vars);
	else if (!game->over)
		keys(keycode, vars);
	mlx_clear_window(game->mlx, game->win);
	drw_map(game);
	if (game->x_player != old_x || game->y_player != old_y)
	{
		ft_putstr("Moves :");
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
	}
	return (0);
}
