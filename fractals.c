#include "fractals.h"

t_complex	get_fractal_default_c(char c)
{
	if (c == 'j')
		return (complex(.285, .013));
	if (c == 'c' || c == '2')
		return (complex(.42, .42));
	return (complex(0, 0));
}

t_fractal_function	get_fractal(int i)
{
	unsigned int	(*g_fractals [256])(t_mlx_win *, int, int);
	int				y;

	y = 0;
	while (y < 256)
		g_fractals[y++] = 0;
	g_fractals['c'] = charbon;
	g_fractals['m'] = mandlebrot;
	g_fractals['j'] = julia;
	g_fractals['2'] = charbon2;
	return (g_fractals[i]);
}

