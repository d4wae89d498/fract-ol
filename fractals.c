/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 19:27:10 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "window.h"
#include "mymath.h"
#include "stdio.h"
#include "unistd.h"

static ftype fparse(char *str)
{
	ftype	o;
	ftype	d;
	int 	sign;
	int 	i;

	o = 0;
	if (*str == '-')
	{
		str += 1;
		sign = -1;
	}
	else
	{
		if (*str == '+')
			str += 1;
		sign = 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		o *= 10;
		o += *str - '0';
		str += 1;
	}
	d = 0;
	if (*str == '.')
	{
		str += 1;
	}
	i = 0;
	while (str[i])
	{
		i += 1;
	}
	if (i)
		i -= 1;
	// todo <<< fix me, may work by startin from eos
	while (i >= 0 && str[i] >= '0' && str[i] <= '9')
	{
		d += str[i] - '0';
		d /= 10;
		i -= 1;
	}
	if (str[i])
		write(1, "error\n", 6);
	return (o + d);
}

void	parse_im_re(t_mlx_win *win, int ac, char **av)
{
	t_complex	c;

	if (ac > 2)
	{
		c.r = fparse(av[2]);
		c.i = fparse(av[3]);
	}
	printf("Re=%Lf Im=%Lf\n", (long double) c.r, (long double) c.i);

	(void) win;
}

#if THREADS == 1

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
				i * 2, i * 1.1, i * 4, 0});
			x += 1;
		}
		y += 1;
	}
	return (!ft_mlx_draw(win));
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
				i * 2, i * 1.1, i * 4, 0});
			x += 1;
		}
		y += 1;
	}
	return (0);
}

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

#endif
