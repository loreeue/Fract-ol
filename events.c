/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:39:23 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:34:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	else if (keysym == XK_space)
		fractal->color_shift = (fractal->color_shift + 1) % 3;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (ft_map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	if (ft_strncmp(fractal->name, "burningship", 12) == 0)
		mouse_im = (ft_map(y, -2, 2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
	else
		mouse_im = (ft_map(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	else
		return (0);
	fractal->shift_x = mouse_re - (ft_map(x, -2, 2, WIDTH) * fractal->zoom);
	if (ft_strncmp(fractal->name, "burningship", 12) == 0)
		fractal->shift_y = mouse_im - (ft_map(y, -2, 2, HEIGHT)
				* fractal->zoom);
	else
		fractal->shift_y = mouse_im - (ft_map(y, 2, -2, HEIGHT)
				* fractal->zoom);
	ft_fractal_render(fractal);
	return (0);
}

int	ft_julia_track(int x, int y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		fractal->julia_x = (ft_map(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (ft_map(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		ft_fractal_render(fractal);
	}
	return (0);
}
