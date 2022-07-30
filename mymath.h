/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:30:40 by mafaussu          #+#    #+#             */
/*   Updated: 2022/07/30 10:36:53 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATH_H
# define MYMATH_H
# include "math.h"
# define COMPLEX_WITH_GCC 0
# if COMPLEX_WITH_GCC == 0

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;
# else
#  error "NOP"
/*
 *typedef _Complex long double	t_complex;
 */
# endif

long double	sqr(long double k);
long double	re(t_complex c);
long double	im(t_complex c);
t_complex	ft_complex(long double r, long double i);
t_complex	ft_complex_sqr(t_complex z);
t_complex	ft_complex_add(t_complex a, t_complex b);
t_complex	ft_complex_mul(t_complex a, t_complex b);
#endif
