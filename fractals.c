#include "window.h"
#include "complex.h"
#include <stdio.h>

t_complex get_c(int o, t_complex c)
{
    static t_complex cd;

    if (o)
        cd = c;
    return (cd);
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
            c = ft_complex(2 * 1.6 * ((long double)x / win->width - 0.5), 2 * 0.9 * ((long double)y /  win->height - 0.5));
            z = ft_complex(0,0);
            i = 0;
            while (i < 256 && sqr(re(z)) + sqr(im(z)) < 4)
            {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            ft_mlx_pixel(*win, x, y, *(unsigned int*)(unsigned char[4]){0,i,i,i});
            x += 1;
        }
        y += 1;
    }
    return (!ft_mlx_draw(win));
}

int julia(t_mlx_win *win)
{
    ft_mlx_pixel(*win, 10, 10, 0x00FFFF00);
    ft_mlx_pixel(*win, 11, 10, 0xFFFFFF00);
    ft_mlx_pixel(*win, 10, 11, 0x0F0F0F0F);
    ft_mlx_pixel(*win, 11, 11, 0x00FF0000);
    return (!ft_mlx_draw(win));
}

int bifurcation(t_mlx_win *win)
{
    ft_mlx_pixel(*win, 10, 10, 0x00FFFF00);
    ft_mlx_pixel(*win, 11, 10, 0xFFFFFF00);
    ft_mlx_pixel(*win, 10, 11, 0x0F0F0F0F);
    ft_mlx_pixel(*win, 11, 11, 0x00FF0000);
    return (!ft_mlx_draw(win));
}
