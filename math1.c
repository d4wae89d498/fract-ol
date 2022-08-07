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

ftype	re(t_complex c)
{
	return (c.r);
}

ftype	im(t_complex c)
{
	return (c.i);
}

t_complex	ft_complex(ftype r, ftype i)
{
	return ((t_complex){r, i});
}
