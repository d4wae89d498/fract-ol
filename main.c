#include "window.h"
#include "stdio.h"
#include "stdlib.h"
#ifndef M_SCREEN_SCALE
# define M_SCREEN_SCALE 0.5
#endif
static int mousemove (int x, int y, t_mlx_win *data)
{
	(void)data;
//    data->ypos = (int)(y * 0.1);
 //   data->xpos = (int)(x * 0.1);
	printf("mouse move:\t[x=%i y=%i]\n", x, y);
	return (0);
}

static int mousedown(int button, int x, int y, t_mlx_win *data)
{
    (void)x;
    (void)y;
    printf("mouse: %p %i\n", data,  button);

    if (button == 1)
    {
        data->zoom *= 0.80;
    }
    else
    {
        data->zoom *= 1.20;
    }
    printf("%i\n", (data->height));

  //  data->ypos = y;
    //data->xpos = x;

    printf("draawing...\n");
    mandlebrot(data);
    printf("done.\n");
	(void) data; (void) button;
	//printf("mouse code: [zoom: %Lf]\t%i\n", data->zoom, keycode);
	return (0);
}

static int	keydown(int keycode, t_mlx_win *data)
{
    (void) data;
    printf("key: %p %i\n", data, keycode);
	printf("key code:\t%i\n", keycode);
	if (keycode == 53)
    {
        ft_mlx_win_delete(*data);
        exit (0);
	}
    if (keycode == 123)
        data->xpos -= 0.10;
    else if (keycode == 124)
        data->xpos += 0.10;
    else if (keycode == 125)
        data->ypos += 0.10;
    else if (keycode == 126)
        data->ypos -= 0.10;
    mandlebrot(data);
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
    // tick..
    (void) data;
    return (0);
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
    ft_mlx_hook_mousedown(&win, mousedown);
    ft_mlx_hook_destroy(&win, destroy);
    ft_mlx_hook_mousemove(&win, mousemove);
    ft_mlx_hook_keydown(&win, keydown);
    ft_mlx_loop(&win, loop);
    mlx_loop(win.mlx);
    printf("anormal exit..");
	destroy(&win);
    return (0);
}
