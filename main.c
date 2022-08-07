/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:55 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 20:34:28 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "fractals.h"
#include "stdlib.h"
#include "unistd.h"

static int	mousedown(int button, int x, int y, t_mlx_win *data)
{
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
	t_complex	c;

	if ((ac != 2 && ac != 4) || !get_fractal((int)av[1][0]) || av[1][1])
		return (usage());
	if (ac == 4)
		c = ft_parse_complex(av[2], av[3]);
	else
		c = get_fractal_default_c(av[1][0]);
	win = ft_mlx_win("fract-ol", (int)(1024), (int)(720));
	win.fractal = av[1][0];
	win.c = c;
	if (win.error)
	{
		write(1, "MLX initialisation error\n", 25);
		return (2);
	}
	draw_fractal(&win);
	ft_mlx_hook_mousedown(&win, mousedown);
	ft_mlx_hook_keydown(&win, keydown);
	mlx_loop(win.mlx);
	ft_mlx_win_delete(win);
	return (0);
}
