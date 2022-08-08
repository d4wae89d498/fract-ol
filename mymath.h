/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:30:40 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/08 17:48:21 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATH_H
# define MYMATH_H
# include "math.h"

typedef float		t_float;
typedef struct s_complex
{
	t_float	r;
	t_float	i;
}	t_complex;
t_float				sqr(t_float k);
t_float				re(t_complex c);
t_float				im(t_complex c);
t_complex			complex(t_float r, t_float i);
t_complex			complex_sqr(t_complex z);
t_complex			complex_add(t_complex a, t_complex b);
t_complex			complex_mul(t_complex a, t_complex b);
t_float				parse_float(char *str);
#endif
