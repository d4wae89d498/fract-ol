#include "window.h"
#include "stdio.h"
#include "stdlib.h"
#ifndef M_SCREEN_SCALE
# define M_SCREEN_SCALE 1.5
#endif
static int mousemove (int x, int y, t_mlx_win *data)
{
	(void)data;
	printf("mouse move:\t[x=%i y=%i]\n", x, y);
	return (0);
}

static int mousedown(int keycode, t_mlx_win *data)
{
	(void) data;
	printf("mouse code:\t%i\n", keycode);
	return (0);
}

static int	keydown(int keycode, t_mlx_win *data)
{
    (void) data;
	printf("key code:\t%i\n", keycode);
	if (keycode == 53)
    {
        ft_mlx_win_delete(*data);
        exit (0);
	}
    if (keycode == 123)
        printf("LEFT\n");
    else if (keycode == 124)
        printf("RIGHT\n");
    else if (keycode == 125)
        printf("DOWN");
    else if (keycode == 126)
        printf("TOP\n");
    return (0);
}

static int	destroy(t_mlx_win *data)
{
	ft_mlx_win_delete(*data);
    exit (0);
}

static int usage(char *ex)
{
    return (printf("usage: %s <char>\n"
        "\t- m mandlebrot\n"
        "\t- j julia\n"
        "\t- b bifurcation\n", ex) % 1);
}

int(*const g_fractals[255])(t_mlx_win *) = {
        ['m'] = mandlebrot,
        ['j'] = julia,
        ['b'] = bifurcation
};

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
    win = ft_mlx_win("fract-ol", (int)(1920 * M_SCREEN_SCALE),
                     (int)(1080 * M_SCREEN_SCALE));
    if (win.error)
    {
        printf ("Initialisation issue.. %p %p %p %p.\n",
                win.mlx , win.win ,win.img.img , win.img.addr);
        destroy(&win);
    }
    if (g_fractals[(int)av[1][0]](&win))
    {
        printf("drawing issue...\n");
        destroy(&win);
    }
    ft_mlx_hook_mousedown(win, mousedown);
    ft_mlx_hook_destroy(win, destroy);
    ft_mlx_hook_mousemove(win, mousemove);
    ft_mlx_hook_keydown(win, keydown);
    ft_mlx_loop();
    printf("anormal exit..");
	destroy(&win);
    return (0);
}
