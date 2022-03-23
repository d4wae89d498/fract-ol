//
// Created by mfaussur on 23/03/2022.
//

#ifndef COMPLEX_H
# define COMPLEX_H
# include "math.h"
# define COMPLEX_WITH_GCC 1
# if COMPLEX_WITH_GCC == 0
typedef struct s_complex
{
    long double r;
    long double i;
}   t_complex;
#else
typedef _Complex long double t_complex;
#endif
long double sqr(long double k);
long double re(t_complex c);
long double im(t_complex c);
t_complex ft_complex(long double r, long double i);
t_complex ft_complex_sqr(t_complex z);
t_complex ft_complex_add(t_complex a, t_complex b);
t_complex ft_complex_mul(t_complex a, t_complex b);
#endif //COMPLEX_H
