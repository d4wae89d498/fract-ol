/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/30 12:25:22 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "mymath.h"
#include "stdio.h"
#include "pthread.h"

int mandlebrot(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
			c = ft_complex(1.6 * 3 * ((((long double) x  - win->xpos) / win->width * win->zoom   ) - 1.3),
                           0.9 * 3 * ((((long double) y - win->ypos) /  win->height * win->zoom   )  - 1.3));
            z = ft_complex(0, 0);
            i = 0;
 			while (i < 64 && sqr(re(z)) + sqr(im(z)) < 4) {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= 0x100121;
            ft_mlx_pixel(win, x, y, i);
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

// mandelia == init C with mandlebrot

int julia(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
			z = ft_complex(1.6 * 3 * ((((long double) x  - win->xpos) / win->width * win->zoom   ) - 1.3),
                           0.9 * 3 * ((((long double) y - win->ypos) /  win->height * win->zoom   )  - 1.3));

            //z = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);
          	c = ft_complex(0,.285 + 0.013);
            i = 0;
            while (i < 66 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= (255 / 7);
            ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){0,i*1,i*1.1,i*2});
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

int julebrot(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
			z = ft_complex(1.6 * 3 * ((((long double) x  - win->xpos) / win->width * win->zoom   ) - 1.3),
                           0.9 * 3 * ((((long double) y - win->ypos) /  win->height * win->zoom   )  - 1.3));

   
			c = ft_complex(win->xpos* 0.001, win->ypos * 0.001);


		/*	c = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);*/
          	//z = ft_complex(0,.285 + 0.013);
            i = 0;
            while (i < 66 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_mul(ft_complex_add(ft_complex_sqr(z), c), z);
                i += 1;
            }
            i *= (255 / 7);
            ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){0,i*1,i*1.1,i*2});
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

int mandleia(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
			z = ft_complex(1.6 * 3 * ((((long double) x  - win->xpos) / win->width * win->zoom   ) - 1.3),
                           0.9 * 3 * ((((long double) y - win->ypos) /  win->height * win->zoom   )  - 1.3));

   
			c = ft_complex(win->xpos* 0.001, win->ypos * 0.001);


		/*	c = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);*/
          	//z = ft_complex(0,.285 + 0.013);
            i = 0;
            while (i < 66 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= (255 / 7);
            ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){0,i*1,i*1.1,i*2});
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}


int charbocmieu(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
			c = ft_complex(1.6 * 3 * ((((long double) x  - win->xpos) / win->width * win->zoom   ) - 1.3),
                           0.9 * 3 * ((((long double) y - win->ypos) /  win->height * win->zoom   )  - 1.3));

   
	//		z = ft_complex(win->xpos* 0.001, win->ypos * 0.001);


			z = ft_complex(0.42, 0.42);
	
			//z = ft_complex(0.042, 0.021);


			/*	c = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);*/
          	//z = ft_complex(0,.285 + 0.013);
            i = 0;
            while (i < 66 && sqr(re(z)) + sqr(im(z)) < 4)
            {
              	// was mul (.., z)
				z = ft_complex_sqr(ft_complex_add(ft_complex_sqr(z), c));//, z);
                i += 1;
            }
            //i *= 0x000002;
			//    i *= (255 / 7);
            ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){i*2,i*1.1,i*4, 0});
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}


