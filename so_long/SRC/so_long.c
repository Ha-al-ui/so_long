/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:48 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:48 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_ber(char *str)
{
    int i;

    i = ft_strlen(str);
    if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b' && str[i - 4] == '.')
        return (1);
    else
        ft_error("Error: Your map file must have '.ber' extention\n");
        return (0); 
}

int close_game(void *vars)
{
    t_game *game = vars;
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int main(int ac, char **av)
{
    t_game game;

    if (ac == 2)
    {
        check_ber(av[1]);
        game.map = read_map(av[1]);
        if(!game.map)
        {
            ft_error("Error: Map not Valid\n");
            return (0);
        }
        if (map_check(&game))
        {
            init_game(&game);
            //mouvments
            mlx_key_hook(game.win, mouve, &game);
            mlx_hook(game.win, 17, 0, close_game, &game);
            mlx_loop(game.mlx);
        }
    }
    else
        ft_error("Error: Invalid number of arguments\n");
    return (0);
}