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

int 	main(int argc, char** argv) {
	t_fractol* fractol;

	fractol = init();
	ft_bzero(fractol->image.data, WIDTH * HEIGHT* sizeof(int));
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->image.img_ptr, 0, 0);
	hooks(fractol);
	return 0;
}