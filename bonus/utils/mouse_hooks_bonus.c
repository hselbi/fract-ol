/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:57:46 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:42:24 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	julia_mouse_hook(int mousecode, int x_mouse, int y_mouse, t_julia *vars)
{
	double	x_range;
	double	y_range;

	x_range = (double)x_mouse * (vars->real_xmax - vars->real_xmin)
		/ (double)vars->max_x + vars->real_xmin;
	y_range = (double)y_mouse * (vars->real_ymax - vars->real_ymin)
		/ (double)vars->max_y + vars->real_ymin;
	if (mousecode == 4 || mousecode == 5)
	{
		julia_zoom(vars, x_range, y_range, mousecode);
		julia_draw(vars);
	}
	return (0);
}

int	burn_mouse_hook(int mousecode, int x_mouse, int y_mouse, t_burn *vars)
{
	double	x_range;
	double	y_range;

	x_range = (double)x_mouse * (vars->real_xmax - vars->real_xmin)
		/ (double)vars->max_x + vars->real_xmin;
	y_range = (double)y_mouse * (vars->real_ymax - vars->real_ymin)
		/ (double)vars->max_y + vars->real_ymin;
	if (mousecode == 4 || mousecode == 5)
	{
		burn_zoom(vars, x_range, y_range, mousecode);
		burn_draw(vars);
	}
	return (0);
}

int	mandel_mouse_hook(int mousecode, int x_mouse, int y_mouse, t_mandel *vars)
{
	double	x_range;
	double	y_range;

	x_range = (double)x_mouse * (vars->real_xmax - vars->real_xmin)
		/ (double)vars->max_x + vars->real_xmin;
	y_range = (double)y_mouse * (vars->real_ymax - vars->real_ymin)
		/ (double)vars->max_y + vars->real_ymin;
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
