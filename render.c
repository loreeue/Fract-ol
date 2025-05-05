/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:55 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:24:30 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	ft_mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

t_complex	ft_handle_constant(int x, int y, t_fractal *fractal)
{
	t_complex	z;

	z.x = (ft_map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	if (ft_strncmp(fractal->name, "burningship", 12) == 0)
		z.y = (ft_map(y, -2, +2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	else
		z.y = (ft_map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	return (z);
}

/*
	MANDELBROT: z = z² + c

	JULIA: z = pixel_point + cte
	(params./fractol julia)
*/
static void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	i = 0;
	z = ft_handle_constant(x, y, fractal);
	ft_mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		if (ft_strncmp(fractal->name, "burningship", 12) == 0)
			z = ft_sum_complex(ft_square_complex_abs(z), c);
		else
			z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_handle_color(fractal, i);
			ft_my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_my_pixel_put(x, y, &fractal->img, WHITE);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr,
		0, 0);
}
