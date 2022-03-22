#include "fract-ol.h"


inline long double	ft_sqr(long double x)
{
	return (x * x);
}



void	interpret(t_complex *registers)
{
	t_complex	*a;
	t_complex	*b;
	long double	r;
	long double i;

	a = registers;
	b = registers + 1;
	r = b->r * b->r - b->i * b->i;
	i = b->r * b->i + b->i * b->r;
	b->r = r + a->r;
	b->i = i + a->i;
}


