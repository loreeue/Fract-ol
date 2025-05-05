/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:47:33 by loruzqui          #+#    #+#             */
/*   Updated: 2025/04/29 19:14:29 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_check_chars(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!ft_isdigit(s1[i]) && s1[i] != '.')
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		if (!ft_isdigit(s2[i]) && s2[i] != '.')
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "burningship", 12) == 0))
	{
		fractal.name = argv[1];
		if (ft_strncmp(fractal.name, "julia", 6) == 0)
		{
			ft_check_chars(argv[2], argv[3]);
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		ft_fractal_init(&fractal);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
