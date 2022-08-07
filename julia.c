/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 23:39:15 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

unsigned int	julia(t_mlx_win *win, int x, int y)
{
	int			i;
	t_complex	c;
	t_complex	z;

	z = ft_complex(1.6 * 3 * ((((long double) x
						- win->xpos) / win->width * win->zoom) - 1.3),
			0.9 * 3 * ((((long double) y
						- win->ypos) / win->height * win->zoom) - 1.3));
	c = win->c;
	i = 0;
	while (i < ITER && sqr(re(z)) + sqr(im(z)) < OPT2)
	{
		z = ft_complex_add(ft_complex_sqr(z), c);
		i += 1;
	}
	return (i);
}
