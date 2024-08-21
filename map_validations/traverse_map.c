#include "../header/so_long.h"

void    fill(char **map, t_pos current)
{
    if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'c' || map[current.y][current.x] == 'e'
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
    fill(map, (t_pos){current.y, current.x + 1});
    fill(map, (t_pos){current.y, current.x - 1});
    fill(map, (t_pos){current.y + 1, current.x});
    fill(map, (t_pos){current.y - 1, current.x});
}

void    reverse_fill(char **map, t_pos current)
{
    if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'C' || map[current.y][current.x] == 'E'
                || map[current.y][current.x] == '0' || map[current.y][current.x] == 'P')
        return ;
    if (map[current.y][current.x] == 'p')
        map[current.y][current.x] = 'P';
    else if (map[current.y][current.x] == 'c')
        map[current.y][current.x] = 'C';
    else if (map[current.y][current.x] == 'e')
        map[current.y][current.x] = 'E';
    else
        map[current.y][current.x] = '0';
    reverse_fill(map, (t_pos){current.y, current.x + 1});
    reverse_fill(map, (t_pos){current.y, current.x - 1});
    reverse_fill(map, (t_pos){current.y + 1, current.x});
    reverse_fill(map, (t_pos){current.y - 1, current.x});
}

void    fill_special_map(char **map, t_pos current)
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
    fill_special_map(map, (t_pos){current.y, current.x + 1});
    fill_special_map(map, (t_pos){current.y, current.x - 1});
    fill_special_map(map, (t_pos){current.y + 1, current.x});
    fill_special_map(map, (t_pos){current.y - 1, current.x});
}

void	traverse_map(char **map, t_pos begin, char *path)
{
	t_pos	pos;

	(void)path;
	fill(map, begin);
	/* Currently in the line below I am checkin if there is still P , E or C
	characters 'couse  the map must be changed after its traversing */
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'P'
				|| map[pos.y][pos.x] == 'C')
				map_error(map);
		}
	}
	/*Now I reverse the alterations I made in the first call of fill*/
    reverse_fill(map, begin);
    fill_special_map(map, begin);
    pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
			if (map[pos.y][pos.x] == 'C')
				map_error(map);
	}
    reverse_fill(map, begin);
    pos.y = -1;
	while (map[++pos.y])
        printf("%s\n", map[pos.y]);
}
