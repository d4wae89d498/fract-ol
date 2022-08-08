/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:31:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/08 17:31:43 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

t_complex	get_position_complex(t_mlx_win *win, int x, int y)
{
	return (complex(RATIO_WIDTH * 3 * ((((long double) x
						- win->xpos) / WIDTH * win->zoom) - 1.3),
			RATIO_HEIGHT * 3 * ((((long double) y
						- win->ypos) / HEIGHT * win->zoom) - 1.3)));
}
