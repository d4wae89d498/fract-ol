#include "fract-ol.h"
#ifndef HEIGHT
# define HEIGHT 1080
#endif
#ifndef WIDTH
# define WIDTH 1920
#endif

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char 	b;
}	t_color;

t_color palette[3] = {{255,0,0},{0,255,0},{0,0,0}};



int ft_interpolate(unsigned long long i)
{
	return *(int*)(unsigned char[4]){ 0, i, i, i};
}



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);


	t_complex 			registers[4];
	unsigned long long	i;
	unsigned long long	x;
	unsigned long long	y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			registers[0].r = 2 * 1.6 * ((long double)x / (long double)WIDTH - 0.5);
			registers[0].i = 2 * 0.9 * ((long double)y /  (long double)HEIGHT - 0.5);
			i = 1;
			while (i < 4)
			{
				registers[i].r = 0;
				registers[i].i = 0;
				i += 1;
			}
			i = 0;
			while (i < 255 && sqr(registers[1].r) + sqr(registers[1].i) < 4)
			{
				interpret(registers);
				i += 1;
			}
		

			my_mlx_pixel_put(&img, x, y, ft_interpolate(i));

			x += 1;
		}
		y += 1;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); 


	mlx_loop(mlx);

	return 0;
}
