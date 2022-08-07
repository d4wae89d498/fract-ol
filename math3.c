/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:01:12 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 23:08:22 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"
#include "stdlib.h"
#include "unistd.h"

static ftype	fparse_d(char *str)
{
	ftype	d;
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

ftype	fparse(char *str)
{
	ftype	o;
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
	return ((o + fparse_d(str)) * sign);
}

t_complex	ft_parse_complex(char *re, char *im)
{
	t_complex	c;

	c.r = fparse(re);
	c.i = fparse(im);
	return (c);
}
