/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:05 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:42:03 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	julia_scheme(t_julia *vast, t_pxl *pxl)
{
	double	x_tmp;
	double	y_tmp;
	int		iter;

	iter = 0;
	while (iter < vast->max_inter)
	{
		x_tmp = pxl->x;
		y_tmp = pxl->y;
		pxl->x = x_tmp * x_tmp - y_tmp * y_tmp + vast->imag_x;
		pxl->y = 2 * x_tmp * y_tmp + vast->imag_y;
		if (pxl->x * pxl->x + pxl->y * pxl->y > 4)
			break ;
		iter++;
	}
	return (iter);
}

void	my_mlx_julia_put(t_julia *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
