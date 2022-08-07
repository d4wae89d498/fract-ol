/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:30:40 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 18:51:34 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATH_H
# define MYMATH_H
# include "math.h"
# define COMPLEX_WITH_GCC 0
# if COMPLEX_WITH_GCC == 0

typedef struct s_complex
{
	ftype	r;
	ftype	i;
}	t_complex;
# else
#  error "NOP"
/*
 *typedef _Complex long double	t_complex;
 */
# endif

ftype	sqr(ftype k);
ftype	re(t_complex c);
ftype	im(t_complex c);
t_complex	ft_complex(ftype r, ftype i);
t_complex	ft_complex_sqr(t_complex z);
t_complex	ft_complex_add(t_complex a, t_complex b);
t_complex	ft_complex_mul(t_complex a, t_complex b);
#endif
