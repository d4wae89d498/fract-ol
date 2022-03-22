#ifndef FRACTOL
# define FRACTOL
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#define sqr(x) ((x) * (x))

#ifndef width
# define width 60
#endif
#ifndef height
# define height 20
#endif


inline long double	ft_sqr(long double x);

typedef struct s_complex
{
	long double r;
	long double i;
}	t_complex;
void	interpret(t_complex *registers);

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
#endif
