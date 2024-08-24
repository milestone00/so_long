/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:59:04 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/13 14:59:10 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <mlx.h>
#include "../printf/ft_printf.h"

typedef struct  s_img
{
	char	*path;
	int		width;
	int		height;
}       t_img;

typedef struct  s_pos
{
	int		y;
	int		x;
} 		t_pos;

typedef struct	s_object
{
	t_img	img_inf;
	void	*img;
}		t_object;

typedef struct	s_dispaly
{
    char    	**map;
	void		*mlx;
	void		*mlx_win;
	int			P_y;
	int			P_x;
	int			height;
	int			width;
	int			move;
	t_object	w;
	t_object	p;
	t_object	e;
	t_object	c;
	t_object	o;
}		t_display;

char    **map_reader(char *path_map);
char	**split(char const *s, char c);
char    **map_copy(t_display *screen);
int		window_size(char **map, char flag);
int    	check_collectable(char **map);
int     close_window(t_display *screen);
void	map_error(char **map);
void    map_validator(t_display *screen);
void	free_and_exit(t_display *screen, bool status);
void	free_matrix(char **av);
void    render_img_on_screen(t_display *screen);
void	traverse_map(t_display *screen);
void    move_right(t_display *screen);
void    move_left(t_display *screen);
void    move_up(t_display *screen);
void    move_down(t_display *screen);
void    load_img_to_struct(t_display *screen);

#endif