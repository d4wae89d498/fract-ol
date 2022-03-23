//
// Created by mfaussur on 23/03/2022.
//
#include "complex.h"

long double sqr(long double k)
{
    return (k * k);
}

# if COMPLEX_WITH_GCC == 1

long double re(t_complex c)
{
    return (__real__ c);
}

long double im(t_complex c)
{
    return (__imag__ c);
}

t_complex ft_complex(long double r, long double i)
{
    t_complex c;

    __real__ c = r;
    __imag__ c = i;
    return (c);
}

t_complex ft_complex_add(t_complex a, t_complex b)
{
    return (a + b);
}

t_complex ft_complex_mul(t_complex a, t_complex b)
{
    return (a * b);
}


t_complex ft_complex_sqr(t_complex z)
{
    return (z * z);
}


#else



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

t_complex ft_complex_add(t_complex a, t_complex b)
{
    return (ft_complex(re(a) + re(b), im(a) + im(b)));
}

/*
 * (a+bi)(x+yi) = ax + ayi + xbi + byi²
 * but (i² == -1) so
 * (a+bi)(x+yi) = ax + ayi + xbi - by
 * (a+bi)(x+yi) = ax - by + 2abi
 *
 */
t_complex ft_complex_mul(t_complex a, t_complex b)
{
    return (ft_complex(re(a) * re(b) - im(a) * im(b),
                            2 * re(a) * im(b)
                       ));
}

/*
 * (a+bi)² = a² + 2abi + b²i²
 * but (i² = -1)  so
 * (a+bi)² = a² + 2abi - b²
 * (a+bi)² = a² - b² + 2abi
 */
t_complex ft_complex_sqr(t_complex z)
{
/*    return (ft_complex(sqr(re(z)) - sqr(im(z)),
                        2 * re(z) * im(z) ));*/
    return (ft_complex_mul(z,z));

}

#endif


