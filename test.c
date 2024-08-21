
#include "./header/so_long.h"
#include "./mlx/mlx.h"

// int main(void)
// {
//     void    *mlx_connection;
//     void    *mlx_window;
//     void    *image;



//     mlx_window = NULL;
//     mlx_connection = mlx_init();
//     // mlx_window = mlx_new_window(mlx_connection, 800, 500, "This is a test");
//     mlx_window = mlx_new_image(mlx_connection, 500, 500);
//     mlx_loop(mlx_connection);
// }

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_img	parede;

	mlx = mlx_init();
	parede.relative_path = "./img/cubov2.xpm";
	parede.img_width = 50;
	parede.img_height = 50;
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!"); 
	img = mlx_xpm_file_to_image(mlx, parede.relative_path, &parede.img_width, &parede.img_height);
	mlx_put_image_to_window(mlx, mlx_win, img,0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img,50, 0);
	mlx_put_image_to_window(mlx, mlx_win, img,100, 0);
	mlx_put_image_to_window(mlx, mlx_win, img,150, 0);
	mlx_put_image_to_window(mlx, mlx_win, img,200, 0);
	mlx_put_image_to_window(mlx, mlx_win, img,0, 50);
	mlx_loop(mlx);
}