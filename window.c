//
// Created by mfaussur on 23/03/2022.
//

#include "window.h"

void    *ft_get_mlx()
{
    static void *mlx;

    if (!mlx)
        mlx = mlx_init();
    return (mlx);
}

t_mlx_win  ft_mlx_win(char *title, int width, int height)
{
    void        *mlx;
    t_mlx_win   out;

    mlx = ft_get_mlx();
    out.mlx = mlx;
    if (out.mlx)
        out.win = mlx_new_window(mlx, width, height, title);
    else
        out.win = 0;
    if (out.win)
    {
        out.img.img = mlx_new_image(mlx, width, height);
        out.img.addr = mlx_get_data_addr(out.img.img, &(out.img.bits_per_pixel), &(out.img.line_length),
                                         &(out.img.endian));
    }
    out.width = width;
    out.height = height;
    out.error = !out.mlx || !out.win || !out.img.img || !out.img.addr;
    return (out);
}

int     ft_mlx_draw(t_mlx_win *win)
{
    return (mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0));
}

int     ft_mlx_win_delete(t_mlx_win data)
{
    int r;

    r = mlx_destroy_image(data.mlx, data.img.img);
    r = mlx_destroy_window(data.mlx, data.win) && r;
    return (r);
}

void	ft_mlx_pixel(t_mlx_win win, int x, int y, unsigned int color)
{
    (void) color;
    *(unsigned int *)
    (win.img.addr + (y * win.img.line_length + x * (win.img.bits_per_pixel / 8))) = color;
}

int ft_mlx_loop()
{
    void    *mlx;

    mlx = ft_get_mlx();
    return (mlx_loop(mlx));
}

void   ft_mlx_hook_mousedown(t_mlx_win win, int (*f)(int, t_mlx_win *))
{
    mlx_hook(win.win, ON_MOUSEDOWN, 0, f, &win);
}

void  ft_mlx_hook_keydown(t_mlx_win win, int (*f)(int, t_mlx_win *))
{
    mlx_hook(win.win, ON_KEYDOWN, 0, f, &win);
}

void    ft_mlx_hook_mouseup(t_mlx_win win, int (*f)(int, t_mlx_win *))
{
    mlx_hook(win.win, ON_MOUSEUP, 0, f, &win);
}

void   ft_mlx_hook_keyup(t_mlx_win win, int (*f)(int, t_mlx_win *))
{
    mlx_hook(win.win, ON_KEYUP, 0, f, &win);
}


void   ft_mlx_hook_mousemove(t_mlx_win win, int (*f)(int, int, t_mlx_win *))
{
    mlx_hook(win.win, ON_MOUSEMOVE, 0, f, &win);
}


void   ft_mlx_hook_destroy(t_mlx_win win, int (*f)(t_mlx_win *))
{
    mlx_hook(win.win, ON_DESTROY, 0, f, &win);
}


void   ft_mlx_hook_expose(t_mlx_win win, int (*f)(t_mlx_win *))
{
    mlx_hook(win.win, ON_EXPOSE, 0, f, &win);
}