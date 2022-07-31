/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/31 17:57:22 by mafaussu         ###   ########lyon.fr   */
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
	int 		i;

	n = ((t_thd*) data)->n;
	win = ((t_thd*) data)->win;
	y = (win->height / THREADS * n);
	stop_y =  (win->height / THREADS) * (n + 1);
    while (y < stop_y)
    {
        x = 0;
        while (x < win->width)
        {
			i = g_fractals[g_current](win, x, y);
#if OPT > 0
			if (i >= ITER && x + OPT < win->width)
			{
	
				i = g_fractals[g_current](win, x + OPT, y);
				if (i >= ITER 
#if OPT >= 4
						&& g_fractals[g_current](win, x + (OPT * 1/2), y) >= ITER
#endif	
						)
				{
					int p = 0;
					while (p < OPT)
					{
						ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){i*2,i*1.1,i*4, 0});
						x += 1;
						p += 1;
					}
					continue ;
					
				}
			}
#endif
			ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){i*2,i*1.1,i*4, 0});
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
    return (!ft_mlx_draw(win));
}
