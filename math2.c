/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:27:51 by mafaussu          #+#    #+#             */
/*   Updated: 2022/08/07 18:53:05 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

t_float	sqr(t_float k)
{
	return (k * k);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	return (complex(re(a) + re(b), im(a) + im(b)));
}

/*
 * (a+bi)(x+yi) = ax + ayi + xbi + byi²
 * but (i² == -1) so
 * (a+bi)(x+yi) = ax + ayi + xbi - by
 * (a+bi)(x+yi) = ax - by + 2abi
 *
 */
t_complex	complex_mul(t_complex a, t_complex b)
{
	return (complex(re(a) * re(b) - im(a) * im(b), 2 * re(a) * im(b)));
}

/*
 * (a+bi)² = a² + 2abi + b²i²
 * but (i² = -1)  so
 * (a+bi)² = a² + 2abi - b²
 * (a+bi)² = a² - b² + 2abi
 */
t_complex	complex_sqr(t_complex z)
{
	return (complex(sqr(re(z)) - sqr(im(z)), 2 * re(z) * im(z)));
}
