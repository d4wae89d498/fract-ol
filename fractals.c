#include "window.h"
#include "complex.h"
#include <stdio.h>

t_color color(int i)
{
    t_color o;
    double incr;
    unsigned char c;
    unsigned char r;

    if (i <= 2) {
        return (t_color){.a=0, .r=0, .g=0, .b=0};
    }
    incr = i / 7;
    if (incr < 1)
        incr = 00000.1;
    c = (int)(i / incr) + 1;
    r = (int)(i + 1 - c);
    o.a = 0;
    if (c == 0) {
        o.r = 0;
        o.g = i * r;
        o.b = 0;
    }
    else if (c == 1) {
        o.r = 0;
        o.g = 255;
        o.b = (int)(256 / incr) * r;
    }
    else if (c == 2) {
        o.r = (int)(256 / incr) * r;
        o.g = 255;
        o.b = 255;
    }
    else if (c == 3) {
        o.r = (int)(256 / incr) * r;
        o.g = 0;
        o.b = 255;
    }
    else if (c == 4) {
        o.r = 255;
        o.g = (int)(256 / incr) * r;
        o.b = 255;
    }
    else if (c == 5) {
        o.r = 255;
        o.g = (int)(256 / incr) * r;
        o.b = 0;
    }
    else //if (c == 6)
    {
        o.r = 255;
        o.g = 255;
        o.b = (int)(256 / incr) * r;
    }
    return (o);
}


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
            c = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);
            z = ft_complex(0,0);
            i = 0;
            while (i < 100 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }

            i *= 255 / 100;
            ft_mlx_pixel(win, x, y, *(int*)color(i).bytes);
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

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
            z = ft_complex( win->xpos + win->zoom * 2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5) * win->zoom + win->ypos);
            //z = ft_complex(2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5));
            c = ft_complex(0,.285 + 0.013);
            i = 0;
            while (i < 66 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= (255 / 7);
           // ft_mlx_pixel(*win, x, y, *(unsigned int*)(unsigned char[4]){0,i,i,i});
            ft_mlx_pixel(win, x, y, *(unsigned int*)(unsigned char[4]){0,i,i,i});
         //  ft_mlx_pixel(win, x, y, *(int*)iterations_to_color(i).bytes);
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

int bifurcation(t_mlx_win *win)
{
    ft_mlx_pixel(win, 10, 10, 0x00FFFF00);
    ft_mlx_pixel(win, 11, 10, 0xFFFFFF00);
    ft_mlx_pixel(win, 10, 11, 0x0F0F0F0F);
    ft_mlx_pixel(win, 11, 11, 0x00FF0000);
    return (!ft_mlx_draw(win));
}
