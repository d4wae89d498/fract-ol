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
			i = get_fractal(win->fractal)(win, x, y);
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
			i = get_fractal(win->fractal)(win, x, y);
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
