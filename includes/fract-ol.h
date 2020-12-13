//
// Created by professor on 11/22/20.
//

#ifndef FRACT_OL_FRACT_OL_H
#define FRACT_OL_FRACT_OL_H

#include "libft.h"
#include "mlx.h"

#define WIDTH 1000
#define HEIGHT 1000

typedef struct	s_image
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*data;
}				t_image;

typedef struct s_fractol {
	void *mlx_ptr;
	void *win_ptr;
	t_image image;
	size_t screen_width;
	size_t screen_length;
}			   t_fractol;

#endif //FRACT_OL_FRACT_OL_H
