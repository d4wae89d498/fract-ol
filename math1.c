/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:40:24 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/30 10:45:07 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

long double re(t_complex c)
{
	return (c.r);
}

long double im(t_complex c)
{
	return (c.i);
}

t_complex ft_complex(long double r, long double i)
{
    return ((t_complex) {r, i});
}
