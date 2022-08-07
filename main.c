/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:55 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 19:18:37 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "fractals.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

t_fractal_function	get_fractal(int i)
{
	static unsigned int (*g_fractals [255])(t_mlx_win *, int, int);

	if (!g_fractals['c'])
	{
		g_fractals['c'] = charbon;
		g_fractals['m'] = mandlebrot;
		g_fractals['j'] = julia;
	}
	return (g_fractals[i]);
}

static int	mousedown(int button, int x, int y, t_mlx_win *data)
{
	(void) x;
	(void) y;
	printf("mouse: %p %i\n", data, button);
	if (button == 4 || button == 5)
	{
		if (button == 4)
		{
			data->zoom *= 1.20;
			data->xpos = x - (x - data->xpos) / 1.20;
			data->ypos = y - (y - data->ypos) / 1.20;
		}
		else if (button == 5)
		{
			data->zoom *= 1 / 1.20;
			data->xpos = x - (x - data->xpos) * 1.20;
			data->ypos = y - (y - data->ypos) * 1.20;
		}
	}
	draw_fractal(data);
	return (0);
}

static int	keydown(int keycode, t_mlx_win *data)
{
	printf("key: %p %i\n", data, keycode);
	if (keycode == 53)
	{
		ft_mlx_win_delete(*data);
		exit (0);
	}
	if (keycode == 123)
		data->xpos += data->width / 4;
	else if (keycode == 124)
		data->xpos -= data->width / 4;
	else if (keycode == 125)
		data->ypos -= data->height / 4;
	else if (keycode == 126)
		data->ypos += data->height / 4;
	draw_fractal(data);
	return (0);
}

static int	usage(void)
{
	write(1, "usage: fract-ol <char> <Re> <Im>\n", 33);
	write(1, "\t- m mandlebrot\n", 16);
	write(1, "\t- j julia\n", 11);
	write(1, "\t- c charbon\n", 13);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx_win	win;

	if (ac != 2 && ac != 4)
		return (usage());
	if (!get_fractal((int)av[1][0]) || av[1][1])
	{
		write(1, "Error : requested fractal is not implemented.\n", 46);
		return (usage());
	}
	win = ft_mlx_win("fract-ol", (int)(1024), (int)(720));
	win.fractal = av[1][0];
	parse_im_re(&win, ac, av);
	if (win.error)
	{
		write(1, "MLX initialisation error\n", 25);
		return (2);
	}
	draw_fractal(&win);
	ft_mlx_hook_mousedown(&win, mousedown);
	ft_mlx_hook_keydown(&win, keydown);
	mlx_loop(win.mlx);
	printf("anormal exit..");
	ft_mlx_win_delete(win);
	return (0);
}
