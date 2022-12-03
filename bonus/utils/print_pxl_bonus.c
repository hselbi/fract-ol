/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pxl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:19:01 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:49:59 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static int	color_store(int i)
{
	static const int	color[15] = {
		4333071, //brown
		1640218, //	dark purple
		590127, // light purple
		1892,
		263241, // blue-marine
		797834,
		1594033, //blue
		3767761, //blue2
		8828389, //blue light
		13888760, //blue very light
		16304479, // yllow wall
		16755200, //yellow multard
		13402112, //yellow brownish
		10049280, //brown
		6960131 //dark brown
	};

	return (color[i]);
}

void	julia_iter(t_pxl *pxl, t_julia *vars, int iter)
{
	int	i;
	int	x;
	int	y;

	x = pxl->x_ori;
	y = pxl->y_ori;
	i = color_store(iter % 16);
	if (iter < vars->max_inter && iter > 0)
		return (my_mlx_julia_put(vars, x, y, i * vars->color));
	return (my_mlx_julia_put(vars, x, y, 0x00000000));
}

void	burn_iter(t_pxl *pxl, t_burn *vars, int iter)
{
	int	i;
	int	x;
	int	y;

	x = pxl->x_ori;
	y = pxl->y_ori;
	i = color_store(iter % 16);
	if (iter < vars->max_inter && iter > 0)
		return (my_mlx_burn_put(vars, x, y, i * vars->color));
	return (my_mlx_burn_put(vars, x, y, 0x00000000));
}

void	mandel_iter(t_pxl *pxl, t_mandel *vars, int iter)
{
	int	i;
	int	x;
	int	y;

	x = pxl->x_ori;
	y = pxl->y_ori;
	i = color_store(iter % 16);
	if (iter < vars->max_inter && iter > 0)
		return (my_mlx_mandel_put(vars, x, y, i * vars->color));
	return (my_mlx_mandel_put(vars, x, y, 0x00000000));
}
