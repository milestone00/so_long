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
	void		*mlx;
	void		*mlx_win;
    char    	**map;
	t_object	wall;
	t_object	player;
}		t_display;

char    **map_reader(char *path_map);
char	**split(char const *s, char c);
int		window_size(char **map, char flag);
void    map_validator(char **map, char *path);
void	map_error(char **map);
void	free_matrix(char **av);
void	free_and_exit(t_display *screen, bool status);
void    render_img_on_screen(t_display screen);
void	traverse_map(char **map, t_pos begin, char *path);

#endif