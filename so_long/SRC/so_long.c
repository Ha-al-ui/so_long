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
        game.map = read_map(av[1]);
        if(!game.map)
        {
            ft_error("Error: Map not found\n");
            return (0);
        }
        if (check_ber(av[1]) && map_check(&game))
        {
            game.mlx = mlx_init();
            if (!game.mlx)
            {
                ft_error("Error: mlx_init() failed\n");
                return (0);
            }
            game.win = mlx_new_window(game.mlx, 1000, 1000, "so_long");
            if (!game.win)
            {
                ft_error("Error: mlx_new_window() failed\n");
                return (0);
            }
            mlx_loop(game.mlx);
        }
    }
    else
        ft_error("Error: Invalid number of arguments\n");
    return (0);
}