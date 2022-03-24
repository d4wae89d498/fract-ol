# fract-ol

Fractal renderer using [minilibx](https://harm-smits.github.io/42docs/libs/minilibx).

![demo picture](/mandelbrot_set.png)

TODO:
- [X] Julia
- [X] Mandelbrot
- [ ] Draw bifurgation diagram 
- [X] Basic movement / zoom
- [ ] Better movement & zom using cursor pos
- [X] Add pthreads suport
- [ ] Add [GMP suport](https://gmplib.org) 
- [ ] Threads should not be created / deleted at each frames
- [ ] Re-use pixels from prev fram
- [ ] Use prev-fram pixels to determine stable area and optimise by avoiding useless calculations
- [ ] Color smoothing 
- [ ] Add a console mode

NOTES:
- CPU has been choosen because arbitrary precision arithmetic is still not compatible with hardware accelerators.
