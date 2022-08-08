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
			i = ((t_fractal*) win->data)->function(win, x, y);
			ft_mlx_pixel(win, x, y, *(unsigned int *)(unsigned char [4]){
				i * 2, i * 1.1, i * 4, 0
			});
			x += 1;
		}
		y += 1;
	}
	return (!ft_mlx_draw(win));
}
