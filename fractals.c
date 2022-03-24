#include "window.h"
#include "complex.h"
#include "stdio.h"
#include "pthread.h"
#define THREADS  32
typedef struct s_tha
{
    int         n;
    t_mlx_win   *win;
} t_tha;
pthread_mutex_t lock;

void *draw_m(void *data)
{
    t_tha       *tha;
    t_mlx_win   *win;
    int         x;
    int         y;
    t_complex   z;
    t_complex   c;
    unsigned    i;

    tha = data;
    win = tha->win;
    printf("drawing thread %i...\n", tha->n);

    y = 0;
    while (y < win->height)
    {
        x = 0 + (win->width / THREADS * tha->n);
        while (x < (win->width / THREADS) * (tha->n + 1))
        {
            c = ft_complex(win->xpos + win->zoom * 2 * 1.6 * ((long double) x / win->width - 0.7),
                           2 * 0.9 * ((long double) y / win->height - 0.5) * win->zoom + win->ypos);
            z = ft_complex(0, 0);
            i = 0;
            while (i < 64 && sqr(re(z)) + sqr(im(z)) < 4) {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= 0x100121;
         //  pthread_mutex_lock(&lock);
            ft_mlx_pixel(win, x, y, i);
           // pthread_mutex_unlock(&lock);

            x += 1;
        }
        y += 1;
    }
    printf("done.\n");
   return (0);
}

int mandlebrot(t_mlx_win *win)
{
    int         i;
    pthread_t   threads[THREADS];
    t_tha       tha[THREADS];


    printf("drawing..\n");
    i = 0;
    while (i < THREADS)
    {
        tha[i] = (t_tha) {i, win};
        pthread_create(threads + i, 0, draw_m, tha + i);
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
int mandlebrot_nonthreaded(t_mlx_win *win)
{
    t_complex   c;
    t_complex   z;
    int         i;
    int         x;
    int         y;

    printf("drawing...\n");

    pthread_t threads[4];
    pthread_create(threads + 0, 0, draw_m, (void*) 101);

    y = 0;
    while (y < win->height)
    {
        x = 0;
        while (x < win->width)
        {
            c = ft_complex(win->xpos + win->zoom * 2 * 1.6 * ((long double) x / win->width - 0.7),
                           2 * 0.9 * ((long double) y / win->height - 0.5) * win->zoom + win->ypos);
            z = ft_complex(0, 0);
            i = 0;
            while (i < 42 && sqr(re(z)) + sqr(im(z)) < 4) {
                z = ft_complex_add(ft_complex_sqr(z), c);
                i += 1;
            }
            i *= 0x100121;
            ft_mlx_pixel(win, x, y, i);//*(int*)(char[4]){0,i,i,i});
            x += 1;
        }
        y += 1;
    }
    printf("done.\n");
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
