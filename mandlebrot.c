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

	c =	get_position_complex(win, x, y);
	z = ((t_fractal*)win->data)->c;
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = complex_add(complex_sqr(z), c);
		i += 1;
	}
	return (i);
}
