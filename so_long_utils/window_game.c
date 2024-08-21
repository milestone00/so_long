/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:50:57 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/15 11:51:01 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int    move(int key_code, t_display *screen)
{
    if ((char)key_code == 27)
        free_and_exit(screen, true);
    return (0);
}

void    render_img_on_screen(t_display screen)
{
    int		x;
    int		y;
    t_object   wall;
    t_object   player;

    wall.img_inf.path = "./img/cubo2.xpm";
    player.img_inf.path = "./img/robo.xpm";
    wall.img = mlx_xpm_file_to_image(screen.mlx, wall.img_inf.path , &wall.img_inf.width, &wall.img_inf.height);
    player.img = mlx_xpm_file_to_image(screen.mlx, player.img_inf.path , &player.img_inf.width, &player.img_inf.height);
    screen.wall = wall;
    screen.player = player;
    y = -1;
    while (screen.map[++y])
    {
        x = -1;
        while (screen.map[y][++x])
        {
            if (screen.map[y][x] == '1')
                mlx_put_image_to_window(screen.mlx, screen.mlx_win, wall.img, x * 50, y * 50);
            if (screen.map[y][x] == 'P')
                mlx_put_image_to_window(screen.mlx, screen.mlx_win, player.img, x * 50, y * 50);
        }
    }
    mlx_hook(screen.mlx_win, 2, 1L<< 0, move, &screen);
    mlx_loop(screen.mlx);
}