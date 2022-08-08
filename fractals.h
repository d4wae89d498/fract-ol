/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:06:00 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/08 17:48:19 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H
# include "window.h"
# include "mymath.h"
# define OPT2 4
# define ITER 64
# define WIDTH 1024
# define HEIGHT 720
# define RATIO_WIDTH 1.6
# define RATIO_HEIGHT 0.9
# define THREADS 1
# define COLOR_SHIFT 1

typedef unsigned int	(*t_fractal_function)(t_mlx_win *, int, int);
typedef struct s_fractal
{
	t_fractal_function	function;
	t_complex			c;
}	t_fractal;

typedef struct s_thd
{
	int					n;
	t_mlx_win			*win;
}	t_thd;
void					parse_im_re(t_mlx_win *win, int ac, char **av);
t_fractal_function		get_fractal(int i);
int						draw_fractal(t_mlx_win *win);
unsigned int			charbon(t_mlx_win *w, int x, int y);
unsigned int			charbon2(t_mlx_win *w, int x, int y);
unsigned int			mandlebrot(t_mlx_win *w, int x, int y);
unsigned int			julia(t_mlx_win *w, int x, int y);
t_complex				get_fractal_default_c(char c);
t_fractal_function		get_fractal(int i);
t_complex				get_position_complex(t_mlx_win *win, int x, int y);
int						draw_fractal(t_mlx_win *win);
#endif
