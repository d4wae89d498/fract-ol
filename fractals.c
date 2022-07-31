/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/31 16:43:42 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "window.h"
#include "mymath.h"
#include "stdio.h"
#include "pthread.h"

typedef struct s_thd
{
    int         n;
    t_mlx_win   *win;
}	t_thd;

void 	*draw_fractal_th(void *data)
{
	t_mlx_win	*win;
	int 		n;
	int			stop_y;
    int         x;
    int         y;

	n = ((t_thd*) data)->n;
	win = ((t_thd*) data)->win;
	y = (win->height / THREADS * n);
	stop_y =  (win->height / THREADS) * (n + 1);
    while (y < stop_y)
    {
        x = 0;
        while (x < win->width)
        {
            ft_mlx_pixel(win, x, y, g_fractals[g_current](win, x, y));
            x += 1;
        }
        y += 1;
    }
	return 0;
}


int 	draw_fractal(t_mlx_win *win)
{
	int         i;
    pthread_t   threads[THREADS];
    t_thd       thd[THREADS];


    printf("drawing..\n");
    i = 0;
    while (i < THREADS)
    {
        thd[i] = (t_thd) {i, win};
        pthread_create(threads + i, 0, draw_fractal_th, thd + i);
        i += 1;
    }
    i = 0;
    while (i < THREADS)
    {
        pthread_join(threads[i], 0);
        i += 1;
    }
    printf("done.\n");
    return (!ft_mlx_draw(win));
}
