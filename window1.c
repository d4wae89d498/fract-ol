/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:43:38 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 17:02:08 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	*ft_get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

t_mlx_win	ft_mlx_win(char *title, int width, int height)
{
	void		*mlx;
	t_mlx_win	out;

	mlx = ft_get_mlx();
	out.mlx = mlx;
	if (out.mlx)
		out.win = mlx_new_window(mlx, width, height, title);
	else
		out.win = 0;
	if (out.win)
	{
		out.img.img = mlx_new_image(mlx, width, height);
		out.img.addr = mlx_get_data_addr(out.img.img, &(out.img.bits_per_pixel),
				&(out.img.line_length),
				&(out.img.endian));
	}
	out.xpos = .0;
	out.ypos = .0;
	out.zoom = 2.5;
	out.width = width;
	out.height = height;
	out.error = (!out.mlx || !out.win || !out.img.img || !out.img.addr);
	return (out);
}

int	ft_mlx_draw(t_mlx_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	return (mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0));
}

int	ft_mlx_win_delete(t_mlx_win data)
{
	mlx_destroy_image(data.mlx, data.img.img);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}

void	ft_mlx_pixel(t_mlx_win *win, int x, int y, unsigned int color)
{
	(void) color;
	*(unsigned int *)
		(win->img.addr
			+ (y * win->img.line_length + x * (win->img.bits_per_pixel / 8)))
		= color;
}

/*
 *	Bellow hooks may be usefull, but it not used currently. 
 *
   void   ft_mlx_hook_keyup(t_mlx_win *win, int (*f)(int, t_mlx_win *))
   {
   mlx_hook(win->win, ON_KEYUP, 0, f, win);
   }


   void   ft_mlx_hook_mousemove(t_mlx_win *win, int (*f)(int, int, t_mlx_win *))
   {
   mlx_hook(win->win, ON_MOUSEMOVE, 0, f, win);
   }





   void   ft_mlx_hook_expose(t_mlx_win *win, int (*f)(t_mlx_win *))
   {
   mlx_hook(win->win, ON_EXPOSE, 0, f, win);
   }
   */
