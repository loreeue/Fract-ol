/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:36 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:14:37 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double unscaled_num, double new_min, double new_max,
	double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_abs(double num)
{
	double	result;

	if (num < 0)
		result = num * (-1);
	else
		result = num;
	return (result);
}

t_complex	ft_square_complex_abs(t_complex z)
{
	t_complex	result;
	double		abs_x;
	double		abs_y;

	abs_x = ft_abs(z.x);
	abs_y = ft_abs(z.y);
	result.x = (abs_x * abs_x) - (abs_y * abs_y);
	result.y = 2 * abs_x * abs_y;
	return (result);
}
