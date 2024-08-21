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

char    **map_reader(char *path_map)
{
    int fd;
    int i;
    char    str[7000000];
    char    buffer;

    fd = open(path_map, O_RDONLY);
    if (fd < 0)
    {
        perror("Open");
        return (NULL);
    }
    i = 0;
    while (1)
    {
        if (read(fd, &buffer, 1) == 1)
            str[i++] = buffer;
        else
        {
            str[i] = '\0';
            break ;
        }
    }
    close(fd);
    return (split(str, '\n'));
}

void    check_invalid_char(char **map)
{
    t_pos   pos;

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

void    map_validator(char **map, char *path)
{
    t_pos     pos;
    t_pos     player_pos;
    int     width;
    int     height;
    short   flag;
    short   c;

    pos.y = -1;
    c = flag = 0;
    player_pos = (t_pos){0, 0};
    width = (window_size(map, 'w') / 50) - 1;
    height = (window_size(map, 'h') / 50) - 1;
    check_invalid_char(map);
    while (map[++pos.y] && pos.y <= height)
    {
        pos.x = -1;
        while (map[pos.y][++pos.x] != '\0')
        {
            if (map[pos.y][pos.x] == 'P')
            {
                ++flag;
                player_pos.y = pos.y;
                player_pos.x = pos.x;
            }
            if (map[pos.y][pos.x] == 'E')
                ++flag;
            if (map[pos.y][pos.x] == 'C')
                ++c;
            if (pos.y == 0 || pos.y == height)
                if (map[pos.y][pos.x] != '1')
                    map_error(map);
            if (pos.x == 0 || pos.x == width)
                if (map[pos.y][pos.x] != '1')
                    map_error(map);
        }
        if (pos.x != (width + 1))
           map_error(map);
    }
    if (flag != 2 || c < 1)
        map_error(map);
    //ft_printf("\nc : %d\n", c);
    //printf("\n%d   %d\n", player_pos.y, player_pos.x);
    traverse_map(map, (t_pos){player_pos.y,  player_pos.x}, path);
    pos.y = -1;
    while (map[++pos.y])
        printf("%s\n", map[pos.y]);
}
