/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:39:00 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/22 22:12:27 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_game(t_game *game)
{
	if (game->over == 1)
		ft_putstr("Congratulations : You Win!\n");
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}
