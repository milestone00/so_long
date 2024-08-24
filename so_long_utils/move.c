/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:54:33 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:37 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int    check_collectable(char **map)
{
    int		c;
    t_pos   pos;

    c = 0;
    pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
			if (map[pos.y][pos.x] == 'C')
                c++;
	}
    return (c);
}

void    move_right(t_display *screen)
{
    int	c;

    c = check_collectable(screen->map);
    if ( screen->map[screen->P_y][screen->P_x + 1] != '1')
    {
        if ((screen->map[screen->P_y][screen->P_x + 1] == 'E') && c > 0)
            return ;
        else if ((screen->map[screen->P_y][screen->P_x + 1] == 'E') && c < 1)
        {
            printf("%d\n", ++screen->move);
            printf("!! CONGRATULATIONS !!\n");
            close_window(screen);
        }
        else if (screen->map[screen->P_y][screen->P_x + 1] == 'C' || screen->map[screen->P_y][screen->P_x + 1] == '0') 
        {
            screen->map[screen->P_y][screen->P_x] = '0';
            screen->map[screen->P_y][++screen->P_x] = 'P';
            printf("%d\n", ++screen->move);
        }
    }
}

void    move_left(t_display *screen)
{
    int	c;

    c = check_collectable(screen->map);
    if ( screen->map[screen->P_y][screen->P_x - 1] != '1')
    {
        if ((screen->map[screen->P_y][screen->P_x - 1] == 'E') && c > 0)
            return ;
        else if ((screen->map[screen->P_y][screen->P_x - 1] == 'E') && c < 1)
        {
            printf("%d\n", ++screen->move);
            printf("!! CONGRATULATIONS !!\n");
            close_window(screen);
        }
        else if (screen->map[screen->P_y][screen->P_x - 1] == 'C' || screen->map[screen->P_y][screen->P_x - 1] == '0') 
        {
            screen->map[screen->P_y][screen->P_x] = '0';
            screen->map[screen->P_y][--screen->P_x] = 'P';
          printf("%d\n", ++screen->move);
        }
    }
}

void    move_up(t_display *screen)
{
    int	c;

    c = check_collectable(screen->map);
    if ( screen->map[screen->P_y - 1][screen->P_x] != '1')
    {
        if ((screen->map[screen->P_y - 1][screen->P_x] == 'E') && c > 0)
            return ;
        else if ((screen->map[screen->P_y - 1][screen->P_x] == 'E') && c < 1)
        {
            printf("%d\n", ++screen->move);
            printf("!! CONGRATULATIONS !!\n");
            close_window(screen);
        }
        else if (screen->map[screen->P_y - 1][screen->P_x] == 'C' || screen->map[screen->P_y - 1][screen->P_x] == '0') 
        {
            screen->map[screen->P_y][screen->P_x] = '0';
            screen->map[--screen->P_y][screen->P_x] = 'P';
            printf("%d\n", ++screen->move);
        }
    }
}

void    move_down(t_display *screen)
{
    int	c;

    c = check_collectable(screen->map);
    if ( screen->map[screen->P_y + 1][screen->P_x] != '1')
    {
        if ((screen->map[screen->P_y + 1][screen->P_x] == 'E') && c > 0)
            return ;
        else if ((screen->map[screen->P_y + 1][screen->P_x] == 'E') && c < 1)
        {
            printf("%d\n", ++screen->move);
            printf("!! CONGRATULATIONS !!\n");
            close_window(screen);
        }
        else if (screen->map[screen->P_y + 1][screen->P_x] == 'C' || screen->map[screen->P_y + 1][screen->P_x] == '0') 
        {
            screen->map[screen->P_y][screen->P_x] = '0';
            screen->map[++screen->P_y][screen->P_x] = 'P';
            printf("%d\n", ++screen->move);
        }
    }
}
