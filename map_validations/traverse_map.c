#include "../header/so_long.h"

void    fill(char **map, t_pos current)
{
    if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'T'
                || map[current.y][current.x] == 'G' || map[current.y][current.x] == 'p')
        return ;
    if (map[current.y][current.x] == 'C')
        map[current.y][current.x] = 'T';
    else if (map[current.y][current.x] == 'P')
        map[current.y][current.x] = 'p';
    else
        map[current.y][current.x] = 'G';
    fill(map, (t_pos){current.y, current.x + 1});
    fill(map, (t_pos){current.y, current.x - 1});
    fill(map, (t_pos){current.y + 1, current.x});
    fill(map, (t_pos){current.y - 1, current.x});
}

void    traverse_map(char **map, t_pos begin, char *path)
{
    t_pos   pos;
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
    /**/
    free_matrix(map);
    map = map_reader(path);
}
