# fract-ol

Fractal renderer using [minilibx](https://harm-smits.github.io/42docs/libs/minilibx).

![demo picture](/mandelbrot_set.png)
![demo picture](/A.png)
![demo picture](/B.png)

TODO:
- [X] Julia
- [X] Mandelbrot
- [X] More fractals
- [ ] Draw bifurgation diagram 
- [X] Basic movement / zoom
- [X] Better movement & zom using cursor pos
- [ ] load fractals as a .so
- [X] Add pthreads suport
- [ ] Add [GMP suport](https://gmplib.org) 
- [ ] Threads should not be created / deleted at each frames
- [ ] Re-use pixels frome prev frame
- [ ] Use prev-frame pixels to determine stable area and optimise by avoiding useless calculations
- [ ] Quternions fractals
- [ ] 3D third person camera
- [ ] Color smoothing 
- [ ] Add a console mode

NOTES:
- CPU has been choosen because arbitrary precision arithmetic is still not compatible with hardware accelerators.
