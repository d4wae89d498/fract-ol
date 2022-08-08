/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:11:25 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 23:12:56 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "window.h"
#include "mymath.h"
#include "unistd.h"
#include "pthread.h"

#if COLOR_SHIFT == 1

void	*draw_fractal_th(void *data)
{
	t_mlx_win	*win;
	int			stop_y;
	int			x;
	int			y;
	int			i;

	win = ((t_thd *) data)->win;
	y = (win->height / THREADS * ((t_thd *) data)->n);
	stop_y = (win->height / THREADS) * (((t_thd *) data)->n + 1);
	while (y < stop_y)
	{
		x = 0;
		while (x < win->width)
		{
			i = ((t_fractal*) win->data)->function(win, x, y);
			ft_mlx_pixel(win, x, y, *(unsigned int *)(unsigned char [4]){
				i * 2 / win->zoom, i * 1.1 / win->zoom, i * 4 / win->zoom, 0
			});
			x += 1;
		}
		y += 1;
	}
	return (0);
}
#else

void	*draw_fractal_th(void *data)
{
	t_mlx_win	*win;
	int			stop_y;
	int			x;
	int			y;
	int			i;

	win = ((t_thd *) data)->win;
	y = (win->height / THREADS * ((t_thd *) data)->n);
	stop_y = (win->height / THREADS) * (((t_thd *) data)->n + 1);
	while (y < stop_y)
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
	return (0);
}
#endif

int	draw_fractal(t_mlx_win *win)
{
	int			i;
	pthread_t	threads[THREADS];
	t_thd		thd[THREADS];

	i = 0;
	while (i < THREADS)
	{
		thd[i] = (t_thd){i, win};
		pthread_create(threads + i, 0, draw_fractal_th, thd + i);
		i += 1;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], 0);
		i += 1;
	}
	return (!ft_mlx_draw(win));
}
