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
    //static int		move;
    if ((char)key_code == 27)
        free_and_exit(screen, true);
    else if (key_code == 65363 || key_code == 100)
        move_right(screen);
    else if (key_code == 65361 || key_code == 97)
        printf("\nleft\n");
    else if (key_code == 65362 || key_code == 119)
        printf("\nup\n");
    else if (key_code == 65364 || key_code == 115)
        printf("\ndown\n");
    return (0);
}

int    close_window(t_display *screen)
{
    free_and_exit(screen, true);
    return (0);
}

void    load_img_to_struct(t_display *screen)
{
    screen->w.img_inf.path = "./img/cubo2.xpm";
    screen->p.img_inf.path = "./img/P_front.xpm";
    screen->e.img_inf.path = "./img/E.xpm";
    screen->c.img_inf.path = "./img/energy.xpm";
    screen->w.img = mlx_xpm_file_to_image(screen->mlx, screen->w.img_inf.path,
                &screen->w.img_inf.width, &screen->w.img_inf.height);
    screen->p.img = mlx_xpm_file_to_image(screen->mlx, screen->p.img_inf.path,
                &screen->p.img_inf.width, &screen->p.img_inf.height);
    screen->e.img = mlx_xpm_file_to_image(screen->mlx, screen->e.img_inf.path,
                &screen->e.img_inf.width, &screen->e.img_inf.height);
    screen->c.img = mlx_xpm_file_to_image(screen->mlx, screen->c.img_inf.path,
                &screen->c.img_inf.width, &screen->c.img_inf.height);
}

static void    hook_handler(t_display *screen)
{
    mlx_hook(screen->mlx_win, 2, 1L<< 0, move, screen);
    mlx_hook(screen->mlx_win, 17, 0, close_window, screen);
    mlx_loop(screen->mlx);
}

void    render_img_on_screen(t_display *screen)
{
    int		x;
    int		y;

    y = -1;
    while (screen->map[++y])
    {
        x = -1;
        while (screen->map[y][++x])
        {
            if (screen->map[y][x] == '1')
                mlx_put_image_to_window(screen->mlx, screen->mlx_win,
                        screen->w.img, x * 50, y * 50);
            else if (screen->map[y][x] == 'P')
                mlx_put_image_to_window(screen->mlx, screen->mlx_win,
                        screen->p.img, x * 50, y * 50);
            else if (screen->map[y][x] == 'E')
                mlx_put_image_to_window(screen->mlx, screen->mlx_win,
                        screen->e.img, x * 50, y * 50);
            else if (screen->map[y][x] == 'C')
                mlx_put_image_to_window(screen->mlx, screen->mlx_win,
                        screen->c.img, x * 50, y * 50);
        }
    }
    hook_handler(screen);
}