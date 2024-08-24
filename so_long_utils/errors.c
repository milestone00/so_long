/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:54:14 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:17 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (!av)
		return ;
	while (av[++i] != NULL)
        free(av[i]);
	free(av);
}

void	free_and_exit(t_display *screen, bool status)
{
	if (screen->w.img)
	    mlx_destroy_image(screen->mlx, screen->w.img);
	if (screen->p.img)
        mlx_destroy_image(screen->mlx, screen->p.img);
	if (screen->e.img)
	    mlx_destroy_image(screen->mlx, screen->e.img);
	if (screen->c.img)
        mlx_destroy_image(screen->mlx, screen->c.img);
	if (screen->o.img)
        mlx_destroy_image(screen->mlx, screen->o.img);
	if (screen->mlx_win)
        mlx_destroy_window(screen->mlx, screen->mlx_win);
	if (screen->mlx)
        mlx_destroy_display(screen->mlx);
	if (screen->mlx)
        free(screen->mlx);
	if (NULL != screen->map)
        free_matrix(screen->map);
	if (status == true)
		exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}

void	map_error(char **map)
{
	free_matrix(map);
	ft_printf("Error\n");
	ft_printf("Invalid map, try to change the map.\n");
	exit(EXIT_FAILURE);
}
