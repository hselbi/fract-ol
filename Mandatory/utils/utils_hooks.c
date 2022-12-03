/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:44:38 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 14:36:53 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/****	julia	****/
void	ft_move_keyj(int key, t_julia *vast, long double s_x, long double s_y)
{
	if (key == UP || key == W)
	{
		vast->real_ymin -= s_y;
		vast->real_ymax -= s_y;
	}
	else if (key == DOWN || key == S)
	{
		vast->real_ymin += s_y;
		vast->real_ymax += s_y;
	}
	else if (key == RIGHT || key == A)
	{
		vast->real_xmin -= s_x;
		vast->real_xmax -= s_x;
	}
	else if (key == LEFT || key == D)
	{
		vast->real_xmin += s_x;
		vast->real_xmax += s_x;
	}
}

/****	mandelbrot	*****/
void	ft_move_keym(int key, t_mandel *vast, long double s_x, long double s_y)
{
	if (key == UP || key == W)
	{
		vast->real_ymin -= s_y;
		vast->real_ymax -= s_y;
	}
	else if (key == DOWN || key == S)
	{
		vast->real_ymin += s_y;
		vast->real_ymax += s_y;
	}
	else if (key == RIGHT || key == A)
	{
		vast->real_xmin -= s_x;
		vast->real_xmax -= s_x;
	}
	else if (key == LEFT || key == D)
	{
		vast->real_xmin += s_x;
		vast->real_xmax += s_x;
	}
}
