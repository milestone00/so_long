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
	if (screen->wall.img)
	    mlx_destroy_image(screen->mlx, screen->wall.img);
	if (screen->player.img)
        mlx_destroy_image(screen->mlx, screen->player.img);
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