/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charbon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:05:48 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/08 17:32:40 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

unsigned int	charbon(t_mlx_win *w, int x, int y)
{
	int			i;
	t_complex	c;
	t_complex	z;

	c = get_position_complex(w, x, y);
	z = ((t_fractal *)w->data)->c;
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = complex_sqr(complex_add(complex_sqr(z), c));
		i += 1;
	}
	return (i);
}
