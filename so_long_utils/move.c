
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
    t_pos   pos;
    int		c;

    c = 0;
    pos.y = -1;
	while (screen->map[++pos.y])
	{
		pos.x = -1;
		while (screen->map[pos.y][++pos.x])
		{
            c = check_collectable(screen->map);
			if (screen->map[pos.y][pos.x] == 'P' && screen->map[pos.y][pos.x + 1] != '1' && c != 0)
            {
               screen->map[pos.y][pos.x] = '0'; 
               screen->map[pos.y][pos.x + 1] = 'P';
               return ;
               //printf("\nx%d  y%d\n",pos.x, pos.y);
            }
		}
	}
    pos.y = -1;
	while (screen->map[++pos.y])
        printf("%s\n", screen->map[pos.y]);
    render_img_on_screen(screen);
}