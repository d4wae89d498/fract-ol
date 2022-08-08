/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:40:24 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 18:51:33 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"
#include "stdlib.h"
#include "unistd.h"

t_float	re(t_complex c)
{
	return (c.r);
}

t_float	im(t_complex c)
{
	return (c.i);
}

t_complex	complex(t_float r, t_float i)
{
	return ((t_complex){r, i});
}

static t_float	parse_float_decimal(char *str)
{
	t_float	d;
	int		i;

	d = 0;
	if (*str == '.')
		str += 1;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i += 1;
	if (str[i])
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (i)
		i -= 1;
	while (i >= 0 && str[i] >= '0' && str[i] <= '9')
	{
		d += str[i--] - '0';
		d /= 10;
	}
	return (d);
}

t_float	parse_float(char *str)
{
	t_float	o;
	int		sign;

	o = 0;
	sign = 1;
	if (*str == '-' && ++str)
		sign = -1;
	else if (*str == '+')
		str += 1;
	while (*str >= '0' && *str <= '9')
	{
		o *= 10;
		o += *str++ - '0';
	}
	return ((o + parse_float_decimal(str)) * sign);
}
