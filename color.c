/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:23:02 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:28:04 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_handle_color(t_fractal *fractal, int i)
{
	int	color;

	color = 0;
	if (fractal->color_shift == 0)
		color = ft_map(i, PURPLE, PINK, fractal->iterations_definition);
	else if (fractal->color_shift == 1)
		color = ft_map(i, BLUE, GREEN, fractal->iterations_definition);
	else if (fractal->color_shift == 2)
		color = ft_map(i, PURPLE, BLUE, fractal->iterations_definition);
	return (color);
}
