/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:42:55 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/31 16:42:32 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "stdio.h"
#include "stdlib.h"
#include "fractals.h"
#ifndef M_SCREEN_SCALE
# define M_SCREEN_SCALE 1
#endif


unsigned int(*const g_fractals[255])(t_mlx_win *, int, int) = {
		['c'] = charbon_draw_pixel
};
int	g_current = 22;

static int mousedown(int button, int x, int y, t_mlx_win *data)
{
    (void) x; (void) y;
    printf("mouse: %p %i\n", data,  button);
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
      	

        printf("zoom: %Lf\n", data->zoom);
        printf("xpos: %Lf\n", data->xpos);
        printf("ypos: %Lf\n", data->ypos);
    }
    printf("%i %i\n", x, y);
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

static int	destroy(t_mlx_win *data)
{
	ft_mlx_win_delete(*data);
    exit (0);
}

static int usage(char *ex)
{
    return (printf("usage: %s <char> <opt1> <opt2>\n"
        "\t- m mandlebrot\n"
        "\t- j julia <Re> <Im> \n"
        "\t- b bifurcation\n", ex) % 1);
}

static int loop(t_mlx_win *data)
{
    (void) data;
    return (0);
}


int	main(int ac, char **av)
{
    t_mlx_win win;

    if (ac != 2)
        return (usage(av[0]));
    if (!g_fractals[(int)av[1][0]] || av[1][1])
    {
        printf("Error : fractal '%s' not exists.", av[1]);
        return (usage(av[0]));
    }
	g_current = av[1][0];
    win = ft_mlx_win("fract-ol", (int)(1024), (int)(720));
    if (win.error)
    {
        printf ("Initialisation issue.. %p %p %p %p.\n",
                win.mlx , win.win ,win.img.img , win.img.addr);
        destroy(&win);
    }
    draw_fractal(&win);
	/*if (g_fractals[(int)av[1][0]](&win))
    {
        printf("drawing issue...\n");
        destroy(&win);
    }*/
    ft_mlx_hook_mousedown(&win, mousedown);
    ft_mlx_hook_destroy(&win, destroy);
    ft_mlx_hook_keydown(&win, keydown);
    ft_mlx_loop(&win, loop);
    mlx_loop(win.mlx);
    printf("anormal exit..");
	destroy(&win);
    return (0);
}
