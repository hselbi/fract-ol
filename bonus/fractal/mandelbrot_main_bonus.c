/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_main_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:52:45 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 14:54:31 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	put_man_pxls(t_pxl *pxl, t_mandel *vars)
{
	int	iter;

	iter = 0;
	pxl->x = ((double)pxl->x_ori / vars->max_x)
		* (vars->real_xmax - vars->real_xmin) + vars->real_xmin;
	pxl->y = ((double)pxl->y_ori / vars->max_y)
		* (vars->real_ymax - vars->real_ymin) + vars->real_ymin;
	iter = mandel_scheme(vars, pxl);
	mandel_iter(pxl, vars, iter);
}

void	mandel_draw(t_mandel *vars)
{
	t_pxl	pxl;
	double	x;
	double	y;

	y = 0;
	vars->img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	while (y < vars->max_y)
	{
		x = 0;
		while (x < vars->max_x)
		{
			pxl.x_ori = x;
			pxl.y_ori = y;
			put_man_pxls(&pxl, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	pre_mandel(t_mandel *vars)
{
	init_mandel(vars);
	mandel_draw(vars);
	mlx_mouse_hook(vars->win, mandel_mouse_hook, vars);
	mlx_key_hook(vars->win, ft_mandel_key, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
}

void	init_mandel(t_mandel *vars)
{
	if (vars->max_inter < 1)
		vars->max_inter = 100;
	vars->real_xmax = 0.48;
	vars->real_ymax = 1.2;
	vars->real_xmin = -2.0;
	vars->real_ymin = -1.2;
	vars->color = 1;
}

void	mandelbrot_set(t_mandel vars)
{
	if (!vars.max_inter)
		vars.max_inter = -1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.max_x, vars.max_y, "Mandelbrot");
	vars.img = mlx_new_image(vars.mlx, vars.max_x, vars.max_y);
	pre_mandel(&vars);
}
