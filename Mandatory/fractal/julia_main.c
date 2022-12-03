/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:46:18 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 14:49:51 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	put_jul_pxls(t_pxl *pxl, t_julia *vast)
{
	int	iter;

	iter = 0;
	pxl->x = (((double)pxl->x_ori / vast->max_x)
			* (vast->real_xmax - vast->real_xmin)) + (vast->real_xmin);
	pxl->y = (((double)pxl->y_ori / vast->max_y)
			* (vast->real_ymax - vast->real_ymin)) + (vast->real_ymin);
	iter = julia_scheme(vast, pxl);
	julia_iter(pxl, vast, iter);
}

void	julia_draw(t_julia *vast)
{
	t_pxl	pxl;
	double	x;
	double	y;

	vast->img = mlx_new_image(vast->mlx, vast->max_x, vast->max_y);
	vast->addr = mlx_get_data_addr(vast->img, &vast->bits_per_pixel,
			&vast->line_length, &vast->endian);
	y = 0;
	while (y < vast->max_y)
	{
		x = 0;
		while (x < vast->max_x)
		{
			pxl.x_ori = x;
			pxl.y_ori = y;
			put_jul_pxls(&pxl, vast);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vast->mlx, vast->win, vast->img, 0, 0);
}

void	init_julia(t_julia *vars)
{
	if (vars->max_inter < 1)
		vars->max_inter = 10;
	vars->real_xmax = 1.5;
	vars->real_ymax = 1.5;
	vars->real_xmin = -1.5;
	vars->real_ymin = -1.5;
	vars->color = 1;
}

void	pre_julia(t_julia *vars)
{
	init_julia(vars);
	julia_draw(vars);
	mlx_key_hook(vars->win, ft_julia_key, vars);
	mlx_mouse_hook(vars->win, julia_mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
}

void	julia_set(t_julia vars)
{
	if (!vars.max_inter)
		vars.max_inter = -1;
	vars.imag_x = -0.7600;
	vars.imag_y = -0.0900;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.max_x, vars.max_y, "Julia");
	vars.img = mlx_new_image(vars.mlx, vars.max_x, vars.max_y);
	pre_julia(&vars);
}
