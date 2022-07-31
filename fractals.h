/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:06:00 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/31 16:48:12 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H
# include "window.h"

# define THREADS 256

int draw_fractal(t_mlx_win *win);

unsigned int charbon_draw_pixel(t_mlx_win *w, int x, int y);

int mandlebrot(t_mlx_win *win);
int julia(t_mlx_win *win);
int mandleia(t_mlx_win *win);
int julebrot(t_mlx_win *win);
int draw_fractal(t_mlx_win *win);

extern unsigned int(*const g_fractals[255])(t_mlx_win *, int, int);
extern int	g_current;
#endif
