/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:50:32 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/15 11:50:38 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**map_reader(char *path_map)
{
	int		fd;
	int		i;
	int		r;
	char	str[7000000];
	char	buffer;

	i = 0;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		perror("Open");
		return (NULL);
	}
	i = 0;
	while (1)
	{
		if ((r = read(fd, &buffer, 1)) == 1)
			str[i++] = buffer;
		else if (r < 1)
			return (NULL);
		else
		{
			str[i] = '\0';
			break ;
		}
	}
	close(fd);
	return (split(str, '\n'));
}

void	check_invalid_char(char **map)
{
	t_pos	pos;

	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] != 'E' && map[pos.y][pos.x] != 'P'
				&& map[pos.y][pos.x] != '0' && map[pos.y][pos.x] != 'C'
				&& map[pos.y][pos.x] != '1')
				map_error(map);
		}
	}
}

void	check_border(t_display *screen, t_pos pos, short *flag)
{
	if (screen->map[pos.y][pos.x] == 'P')
	{
		*flag += 1;
		screen->P_y = pos.y;
		screen->P_x = pos.x;
	}
	if (screen->map[pos.y][pos.x] == 'E')
		*flag += 1;
	if (pos.y == 0 || pos.y == (screen->height / 50) - 1)
		if (screen->map[pos.y][pos.x] != '1')
			map_error(screen->map);
	if (pos.x == 0 || pos.x == (screen->width / 50) - 1)
		if (screen->map[pos.y][pos.x] != '1')
			map_error(screen->map);
}

void	map_validator(t_display *screen)
{
	t_pos	pos;
	short	flag;

	pos.y = -1;
	flag = 0;
	check_invalid_char(screen->map);
	while (screen->map[++pos.y] && pos.y <= (screen->height / 50) - 1)
	{
		pos.x = -1;
		while (screen->map[pos.y][++pos.x] != '\0')
			check_border(screen, (t_pos){pos.y, pos.x}, &flag);
		if (pos.x != (screen->width / 50))
			map_error(screen->map);
	}
	if (flag != 2 || check_collectable(screen->map) < 1)
		map_error(screen->map);
	traverse_map(screen);
}
