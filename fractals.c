/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 22:53:42 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "window.h"
#include "mymath.h"
#include "unistd.h"

t_complex	get_fractal_default_c(char c)
{
	if (c == 'j')
		return (ft_complex(.285, .013));
	if (c == 'c')
		return (ft_complex(.42, .42));
	return (ft_complex(0, 0));
}

t_fractal_function	get_fractal(int i)
{
	static unsigned int	(*g_fractals [255])(t_mlx_win *, int, int);

	if (!g_fractals['c'])
	{
		g_fractals['c'] = charbon;
		g_fractals['m'] = mandlebrot;
		g_fractals['j'] = julia;
	}
	return (g_fractals[i]);
}

int	draw_fractal(t_mlx_win *win)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			i = get_fractal(win->fractal)(win, x, y);
			ft_mlx_pixel(win, x, y, *(unsigned int *)(unsigned char [4]){
				i * 2, i * 1.1, i * 4, 0
			});
			x += 1;
		}
		y += 1;
	}
	return (!ft_mlx_draw(win));
}
