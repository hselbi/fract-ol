/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:57:46 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 15:50:53 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia_mouse_hook(int mousecode, int x_mouse, int y_mouse, t_julia *vars)
{
	double	x_range;
	double	y_range;

	x_mouse = y_mouse;
	x_range = (vars->real_xmax - vars->real_xmin) / (double)vars->max_x;
	y_range = (vars->real_ymax - vars->real_ymin) / (double)vars->max_y;
	if (mousecode == 4 || mousecode == 5)
	{
		julia_zoom(vars, x_range, y_range, mousecode);
		julia_draw(vars);
	}
	return (0);
}

int	mandel_mouse_hook(int mousecode, int x_mouse, int y_mouse, t_mandel *vars)
{
	double	x_range;
	double	y_range;

	x_mouse = y_mouse;
	x_range = (vars->real_xmax - vars->real_xmin)
		/ (double)vars->max_x;
	y_range = (vars->real_ymax - vars->real_ymin)
		/ (double)vars->max_y;
	if (mousecode == 4 || mousecode == 5)
	{
		mandel_zoom(vars, x_range, y_range, mousecode);
		mandel_draw(vars);
	}
	return (0);
}

int	jmove_mouse(int x, int y, t_julia *vars)
{
	if (x >= 0 && y >= 0 && vars->max_x > x && vars->max_y > y)
	{
		y = vars->imag_y + y;
		vars->imag_x = ((x * (vars->real_xmax - vars->real_xmin)
					/ (long double)vars->max_x)) - 1.66;
		vars->imag_y = ((y * (vars->real_ymax - vars->real_ymin)
					/ (long double)vars->max_y)) - 1.51;
		julia_draw(vars);
	}
	return (0);
}
