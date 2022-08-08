/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:23:18 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 23:39:02 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

unsigned int	mandlebrot(t_mlx_win *win, int x, int y)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c = complex(1.6 * 3 * ((((long double) x
						- win->xpos) / win->width * win->zoom) - 1.3),
			0.9 * 3 * ((((long double) y
						- win->ypos) / win->height * win->zoom) - 1.3));
	z = ((t_fractal*)win->data)->c;
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = complex_add(complex_sqr(z), c);
		i += 1;
	}
	return (i);
}
