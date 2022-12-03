/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:14:39 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:42:37 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../fractol_bonus.h"

/********************	julia	*******************************/

void	julia_zoom(t_julia *vars, double range_x, double range_y, int i)
{
	int		iter;
	double	a;

	a = 0.0;
	iter = 2;
	if (i == 4)
	{
		iter = -2;
		a = 1.1;
	}
	else if (i == 5)
	{
		iter = 2;
		a = 0.9;
	}
	vars->max_inter += iter;
	vars->real_xmax = range_x + (vars->real_xmax - range_x) * a;
	vars->real_ymax = range_y + (vars->real_ymax - range_y) * a;
	vars->real_xmin = range_x + (vars->real_xmin - range_x) * a;
	vars->real_ymin = range_y + (vars->real_ymin - range_y) * a;
}

/********************	burn	*********************************/

void	burn_zoom(t_burn *vars, double range_x, double range_y, int i)
{
	int		iter;
	double	a;

	a = 0.0;
	iter = 2;
	if (i == 4)
	{
		iter = -2;
		a = 1.1;
	}
	else if (i == 5)
	{
		iter = 2;
		a = 0.9;
	}
	vars->max_inter += iter;
	vars->real_xmax = range_x + (vars->real_xmax - range_x) * a;
	vars->real_ymax = range_y + (vars->real_ymax - range_y) * a;
	vars->real_xmin = range_x + (vars->real_xmin - range_x) * a;
	vars->real_ymin = range_y + (vars->real_ymin - range_y) * a;
}

/*********************** mandelbrot	**************************/

void	mandel_zoom(t_mandel *vars, double range_x, double range_y, int i)
{
	int		iter;
	double	a;

	a = 0.0;
	iter = 2;
	if (i == 4)
	{
		iter = -2;
		a = 1.1;
	}
	else if (i == 5)
	{
		iter = 2;
		a = 0.9;
	}
	vars->max_inter += iter;
	vars->real_xmax = range_x + (vars->real_xmax - range_x) * a;
	vars->real_ymax = range_y + (vars->real_ymax - range_y) * a;
	vars->real_xmin = range_x + (vars->real_xmin - range_x) * a;
	vars->real_ymin = range_y + (vars->real_ymin - range_y) * a;
}
