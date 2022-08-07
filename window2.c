/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:00:14 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 17:01:39 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	ft_mlx_loop(t_mlx_win *data, int (*f)(t_mlx_win*))
{
	void	*mlx;

	mlx = ft_get_mlx();
	mlx_loop_hook(mlx, f, data);
	return (mlx_loop(mlx));
}

void	ft_mlx_hook_mousedown(t_mlx_win *win,
		int (*f)(int button, int x, int y, t_mlx_win *data))
{
	mlx_mouse_hook(win->win, f, win);
}

void	ft_mlx_hook_keydown(t_mlx_win *win, int (*f)(int, t_mlx_win *))
{
	mlx_hook(win->win, ON_KEYDOWN, 0, f, win);
}

void	ft_mlx_hook_mouseup(t_mlx_win *win, int (*f)(int, t_mlx_win *))
{
	mlx_hook(win->win, ON_MOUSEUP, 0, f, win);
}

void	ft_mlx_hook_destroy(t_mlx_win *win, int (*f)(t_mlx_win *))
{
	mlx_hook(win->win, ON_DESTROY, 0, f, win);
}
