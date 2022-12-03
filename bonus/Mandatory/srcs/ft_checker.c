/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:34:00 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 15:34:29 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_atois(char *str)
{
	int	n;

	n = 0;
	if (*str == 'h' || *str == 'H')
	{
		str++;
		n = ft_atoi(str);
	}
	else if (*str == 'w' || *str == 'W')
	{
		str++;
		n = ft_atoi(str);
	}
	return (n);
}

void	size_check_mandel(int arg, char **str)
{
	t_mandel	vars;

	vars.max_x = 800;
	vars.max_y = 600;
	if (arg > 4)
		arg = 4;
	arg -= 1;
	ft_instractions();
	ft_controls();
	while (arg > 1)
	{
		if (ft_strncmp(str[arg], "h", 1) == 0
			|| ft_strncmp(str[arg], "H", 1) == 0)
			vars.max_y = ft_atois(str[arg]);
		else if (ft_strncmp(str[arg], "w", 1) == 0
			|| ft_strncmp(str[arg], "W", 1) == 0)
			vars.max_x = ft_atois(str[arg]);
		else
			vars.max_inter = (int)ft_atoi(str[arg]);
		arg--;
	}
	mandelbrot_set(vars);
}

void	size_check_julia(int arg, char **str)
{
	t_julia	vars;

	vars.max_x = 800;
	vars.max_y = 600;
	if (arg > 4)
		arg = 4;
	arg -= 1;
	ft_instractions();
	ft_controls();
	while (arg > 1)
	{
		if (ft_strncmp(str[arg], "h", 1) == 0
			|| ft_strncmp(str[arg], "H", 1) == 0)
			vars.max_y = ft_atois(str[arg]);
		else if (ft_strncmp(str[arg], "w", 1) == 0
			|| ft_strncmp(str[arg], "W", 1) == 0)
			vars.max_x = ft_atois(str[arg]);
		else
			vars.max_inter = ft_atoi(str[arg]);
		arg--;
	}
	julia_set(vars);
}
