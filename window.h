/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:20:34 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 23:16:02 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "minilibx/mlx.h"
# include "mymath.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_mlx_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_win {
	void		*mlx;
	void		*win;
	t_mlx_img	img;
	int			width;
	int			height;
	ftype		xpos;
	ftype		ypos;
	ftype		zoom;
	int			error;
	int			thread;
	int			fractal;
	t_complex	c;
}	t_mlx_win;
typedef struct s_color
{
	union {
		char	bytes[4];
		struct {
			unsigned char	a;
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;
		};
	};
}	t_color;
void		*ft_get_mlx(void);
int			ft_mlx_loop(t_mlx_win *data, int (*f)(t_mlx_win *));
void		ft_mlx_pixel(t_mlx_win *data, int x, int y, unsigned int color);
t_mlx_win	ft_mlx_win(char *title, int width, int height);
int			ft_mlx_win_delete(t_mlx_win data);
int			ft_mlx_draw(t_mlx_win *win);
void		ft_mlx_hook_mousedown(t_mlx_win *win,
				int (*f)(int button, int x, int y, t_mlx_win *data));
void		ft_mlx_hook_keydown(t_mlx_win *win, int (*f)(int, t_mlx_win *));
void		ft_mlx_hook_mouseup(t_mlx_win *win, int (*f)(int, t_mlx_win *));
void		ft_mlx_hook_keyup(t_mlx_win *win, int (*f)(int, t_mlx_win *));
void		ft_mlx_hook_mousemove(t_mlx_win *win,
				int (*f)(int, int, t_mlx_win *));
void		ft_mlx_hook_destroy(t_mlx_win *win, int (*f)(t_mlx_win *));
void		ft_mlx_hook_expose(t_mlx_win *win, int (*f)(t_mlx_win *));
#endif
