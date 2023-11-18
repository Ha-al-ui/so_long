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

int main(int ac, char **av)
{
    t_game game;

    if (ac == 2)
    {
        check_ber(av[1]);
        game.map = read_map(av[1]);
        if(!game.map)
        {
            ft_error("Error: Map not found\n");
            return (0);
        }
        if (map_check(&game))
        {
           for (int i = 0; game.map[i] != NULL; i++)
            printf("%s\n", game.map[i]);
        }
    }
    else
        ft_error("Error: Invalid number of arguments\n");
    return (0);
}