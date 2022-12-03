/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:46:23 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:42:20 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

/****	julia	****/

int	ft_julia_key(int key, t_julia *vast)
{
	long double	s_x;
	long double	s_y;

	s_x = (vast->real_xmax - vast->real_xmin) * 0.1;
	s_y = (vast->real_ymax - vast->real_ymin) * 0.1;
	if (key == ESC)
		ft_close(vast);
	else if (key == E)
		vast->max_inter += 2;
	else if (key == R)
		vast->max_inter -= 2;
	else if (key == Z)
		vast->max_inter = 1000;
	else if (key == X)
		vast->max_inter = 10;
	else if (key == SPACE)
		vast->color += 0.5;
	else if (key == C)
		mlx_hook(vast->win, 6, 1L << 6, jmove_mouse, vast);
	else
		ft_move_keyj(key, vast, s_x, s_y);
	julia_draw(vast);
	return (0);
}

/****   burning ship  ****/

int	ft_burn_key(int key, t_burn *vast)
{
	long double	s_x;
	long double	s_y;

	s_x = (vast->real_xmax - vast->real_xmin) * 0.1;
	s_y = (vast->real_ymax - vast->real_ymin) * 0.1;
	if (key == ESC)
	{
		mlx_destroy_window(vast->mlx, vast->win);
		exit(0);
	}
	else if (key == E)
		vast->max_inter += 2;
	else if (key == R)
		vast->max_inter -= 2;
	else if (key == Z)
		vast->max_inter = 1000;
	else if (key == X)
		vast->max_inter = 10;
	else if (key == SPACE)
		vast->color += 0.5;
	else
		ft_move_keyb(key, vast, s_x, s_y);
	burn_draw(vast);
	return (0);
}

/****	mandelbrot	*****/

int	ft_mandel_key(int key, t_mandel *vast)
{
	long double	s_x;
	long double	s_y;

	s_x = (vast->real_xmax - vast->real_xmin) * 0.1;
	s_y = (vast->real_ymax - vast->real_ymin) * 0.1;
	if (key == ESC)
	{
		mlx_destroy_window(vast->mlx, vast->win);
		exit(0);
	}
	else if (key == E)
		vast->max_inter += 2;
	else if (key == R)
		vast->max_inter -= 2;
	else if (key == Z)
		vast->max_inter = 1000;
	else if (key == X)
		vast->max_inter = 10;
	else if (key == SPACE)
		vast->color += 0.5;
	else
		ft_move_keym(key, vast, s_x, s_y);
	mandel_draw(vast);
	return (0);
}

/**		close		**/

int	ft_close(t_julia *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
