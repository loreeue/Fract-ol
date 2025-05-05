/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:43:09 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:27:58 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include <X11/X.h> //window and graphics
# include <X11/keysym.h> //events keys

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or\
\n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH		800
# define HEIGHT		800

# define WHITE	0xFFFFFF
# define PURPLE	0xE6E6FA
# define PINK	0xFFE4E1
# define BLUE 0xADD8E6
# define GREEN 0x98FB98

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_shift;
}				t_fractal;

void		ft_fractal_init(t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);
double		ft_map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
t_complex	ft_square_complex_abs(t_complex z);
int			ft_key_handler(int keysym, t_fractal *fractal);
int			ft_close_handler(t_fractal *fractal);
int			ft_mouse_handler(int button, int x, int y, t_fractal *fractal);
int			ft_julia_track(int x, int y, t_fractal *fractal);
void		ft_malloc_error(void);
int			ft_handle_color(t_fractal *fractal, int i);

#endif
