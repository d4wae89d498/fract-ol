/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/08 17:31:34 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

unsigned int	julia(t_mlx_win *win, int x, int y)
{
	int			i;
	t_complex	c;
	t_complex	z;

	z = get_position_complex(win, x, y);
	c = ((t_fractal *)win->data)->c;
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = complex_add(complex_sqr(z), c);
		i += 1;
	}
	return (i);
}
