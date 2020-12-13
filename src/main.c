//
// Created by professor on 11/22/20.
//
#include "fract-ol.h"

void hooks(t_fractol* fractol) {
	mlx_loop(fractol->mlx_ptr);
}

t_fractol *init() {
	t_fractol* fractol;

	if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		return NULL;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
								      WIDTH, HEIGHT,
								      "FRACT-OL");
	fractol->image.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->image.data =  (int*)mlx_get_data_addr(fractol->image.img_ptr,
												   &fractol->image.bits_per_pixel,
												   &fractol->image.size_line,
												   &fractol->image.endian);

	return fractol;
}

t_complex init_complex(const double real, const double imaginary) {
	t_complex c = {real, imaginary};
	return c;
}

///naive not moving
void mandelbrot(t_fractol* fractol) {
	///min c complex
	const t_complex min_c = {-2., -1.2};
	///max c complex
	const t_complex max_c = {1., min_c.imaginary + (max_c.real - min_c.real) * (double)(HEIGHT / WIDTH) };
	///real factor
	const double real_factor = (max_c.real - min_c.real) / (double)(WIDTH - 1);
	///imaginary factor
	const double imaginary_factor = (max_c.imaginary - min_c.imaginary) / (double)(HEIGHT - 1);
	///temp complex z
	t_complex c;
	///iterations
	const size_t max_iterations = 50;

	register int x;
	register int y;

	x = y = 0;
	while (y < HEIGHT) {
		c.imaginary = max_c.imaginary - (double)y * imaginary_factor;
		x = 0;
		while (x < WIDTH) {
			c.real = min_c.real + (double)x * real_factor;

			t_complex z = init_complex(c.real, c.imaginary);
			size_t iterations = 0;

			while (pow(z.real, 2.) + pow(z.imaginary, 2.) <= 4. && iterations < max_iterations) {
				z = init_complex(pow(z.real, 2.) - pow(z.imaginary, 2.) + c.real,
					 				2. * z.real * z.imaginary + c.imaginary);
				++iterations;

			}
			if (iterations == max_iterations) {
				fractol->image.data[y * WIDTH + x] = 0xFFFFFF;
			}
			++x;
		}
		++y;
	}
}

int 	main(int argc, char** argv) {
	t_fractol* fractol;

	fractol = init();
	ft_bzero(fractol->image.data, WIDTH * HEIGHT* sizeof(int));
	mandelbrot(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr,
						 	fractol->win_ptr,
						 	fractol->image.img_ptr,
						 	0, 0);
	hooks(fractol);
	return 0;
}