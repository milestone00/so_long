/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:56:26 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/23 17:56:34 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	fill(char **map, t_pos current)
{
	if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'c'
		|| map[current.y][current.x] == 'e' || map[current.y][current.x] == 'G'
		|| map[current.y][current.x] == 'p')
		return ;
	if (map[current.y][current.x] == 'C')
		map[current.y][current.x] = 'c';
	else if (map[current.y][current.x] == 'P')
		map[current.y][current.x] = 'p';
	else if (map[current.y][current.x] == 'E')
		map[current.y][current.x] = 'e';
	else
		map[current.y][current.x] = 'G';
	fill(map, (t_pos){current.y, current.x + 1});
	fill(map, (t_pos){current.y, current.x - 1});
	fill(map, (t_pos){current.y + 1, current.x});
	fill(map, (t_pos){current.y - 1, current.x});
}

void	fill_2(char **map, t_pos current)
{
	if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'E'
		|| map[current.y][current.x] == 'G' || map[current.y][current.x] == 'p')
		return ;
	if (map[current.y][current.x] == 'C')
		map[current.y][current.x] = 'c';
	else if (map[current.y][current.x] == 'P')
		map[current.y][current.x] = 'p';
	else if (map[current.y][current.x] == 'E')
		map[current.y][current.x] = 'e';
	else
		map[current.y][current.x] = 'G';
	fill_2(map, (t_pos){current.y, current.x + 1});
	fill_2(map, (t_pos){current.y, current.x - 1});
	fill_2(map, (t_pos){current.y + 1, current.x});
	fill_2(map, (t_pos){current.y - 1, current.x});
}

char	**map_copy(t_display *screen)
{
	t_pos	pos;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * ((screen->height / 50) + 2));
	if (!copy)
		return (NULL);
	pos.y = -1;
	while (screen->map[++pos.y])
	{
		copy[pos.y] = (char *)malloc(sizeof(char) * ((screen->width / 50) + 1));
		if (!copy[pos.y])
		{
			free_matrix(copy);
			return (NULL);
		}
		pos.x = -1;
		while (screen->map[pos.y][++pos.x])
			copy[pos.y][pos.x] = screen->map[pos.y][pos.x];
		copy[pos.y][pos.x] = '\0';
	}
	copy[pos.y] = NULL;
	return (copy);
}

void	traverse_map(t_display *screen)
{
	t_pos	pos;
	char	**copy;

	copy = map_copy(screen);
	fill(copy, (t_pos){screen->P_y, screen->P_x});
	/* Currently in the line below I am checkin if there is still P , E or C
	characters 'couse  the map must be changed after its traversing */
	pos.y = -1;
	while (copy[++pos.y])
	{
		pos.x = -1;
		while (copy[pos.y][++pos.x])
		{
			if (copy[pos.y][pos.x] == 'E' || copy[pos.y][pos.x] == 'P'
				|| copy[pos.y][pos.x] == 'C')
			{
				free_matrix(copy);
				map_error(screen->map);
			}
		}
	}
	free_matrix(copy);
	copy = map_copy(screen);
	fill_2(copy, (t_pos){screen->P_y, screen->P_x});
	/*Now I reverse the alterations I made in the first call of fill*/
	pos.y = -1;
	while (copy[++pos.y])
	{
		pos.x = -1;
		while (copy[pos.y][++pos.x])
			if (copy[pos.y][pos.x] == 'C')
			{
				free_matrix(copy);
				map_error(screen->map);
			}
	}
	free_matrix(copy);
}
