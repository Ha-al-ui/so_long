#include "so_long.h"

void    init_img(t_game *game)
{
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "", &game->img_wid, &game->img_hei);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "", &game->img_wid, &game->img_hei);
    game->img_colect = mlx_xpm_file_to_image(game->mlx, "", &game->img_wid, &game->img_hei);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "", &game->img_wid, &game->img_hei);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "", &game->img_wid, &game->img_hei);

}

static  void    win_size(t_game *game)
{
    int i;

    game->win_width = ft_strlen(game->map[0]) * 32;
    i = 0;
    while (game->map[i])
        i++;
    game->win_height = i * 32;
}

void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    win_size(game);
    game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "so_long");
    init_img(game);
    drw_map(game);
}