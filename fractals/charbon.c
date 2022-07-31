#include "fractals.h"
#include "window.h"
#include "mymath.h"
#include "limits.h"
#include "stdio.h"
unsigned int charbon_draw_pixel(t_mlx_win *w, int x, int y)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c = ft_complex(1.6 * 3 * ((((long double) x  - w->xpos) / w->width * w->zoom   ) - 1.3),
			0.9 * 3 * ((((long double) y - w->ypos) /  w->height * w->zoom   )  - 1.3));
	z = ft_complex(0.42, 0.42);
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = ft_complex_sqr(ft_complex_add(ft_complex_sqr(z), c));
		i += 1;
	}
	return i;
//	return *(unsigned int*)(unsigned char[4]){i*2,i*1.1,i*4, 0};
}
