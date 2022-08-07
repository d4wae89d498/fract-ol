/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:06:00 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 19:16:04 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H
# include "window.h"
# include "mymath.h"
# include "pthread.h"
# define OPT2 4
# define ITER 64
# define THREADS 64
# if THREADS > 1

typedef struct s_thd
{
	int			n;
	t_mlx_win	*win;
}	t_thd;
# endif

void	parse_im_re(t_mlx_win *win, int ac, char **av);
typedef unsigned int(*t_fractal_function)(t_mlx_win *, int, int);
t_fractal_function	get_fractal(int i);
int					draw_fractal(t_mlx_win *win);
unsigned int		charbon(t_mlx_win *w, int x, int y);
unsigned int		mandlebrot(t_mlx_win *, int x, int y);
unsigned int		julia(t_mlx_win *, int x, int y);
#endif
