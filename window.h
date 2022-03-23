//
// Created by mfaussur on 23/03/2022.
//

#ifndef FRACT_OL_WINDOW_H
#define FRACT_OL_WINDOW_H
#include "minilibx/mlx.h"

enum {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
};

typedef struct  s_mlx_img {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}   t_mlx_img;


typedef struct	s_mlx_win {
    void	    *mlx;
    void	    *win;
    t_mlx_img   img;
    int         width;
    int         height;
    int         error;
}   t_mlx_win;
void        *ft_get_mlx();
int         ft_mlx_loop();
void        ft_mlx_pixel(t_mlx_win data, int x, int y, unsigned int color);
t_mlx_win   ft_mlx_win(char *title, int width, int height);
int         ft_mlx_win_delete(t_mlx_win data);
int         ft_mlx_draw(t_mlx_win *win);
void        ft_mlx_hook_mousedown(t_mlx_win win, int (*f)(int, t_mlx_win *));
void        ft_mlx_hook_keydown(t_mlx_win win, int (*f)(int, t_mlx_win *));
void        ft_mlx_hook_mouseup(t_mlx_win win, int (*f)(int, t_mlx_win *));
void        ft_mlx_hook_keyup(t_mlx_win win, int (*f)(int, t_mlx_win *));
void        ft_mlx_hook_mousemove(t_mlx_win win, int (*f)(int, int, t_mlx_win *));
void        ft_mlx_hook_destroy(t_mlx_win win, int (*f)(t_mlx_win *));
void        ft_mlx_hook_expose(t_mlx_win win, int (*f)(t_mlx_win *));

int         mandlebrot(t_mlx_win *win);
int         julia(t_mlx_win *win);
int         bifurcation(t_mlx_win *win);

#endif //FRACT_OL_WINDOW_H
