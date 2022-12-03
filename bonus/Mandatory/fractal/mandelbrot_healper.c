/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_healper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:59:16 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 17:31:33 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandel_scheme(t_mandel *vars, t_pxl *pxl)
{
	double	x;
	double	y;
	double	temp;
	int		inter;

	x = 0;
	y = 0;
	inter = 0;
	while (x * x + y * y <= 4 && inter < vars->max_inter)
	{
		temp = x * x - y * y + pxl->x;
		y = 2 * x * y + pxl->y;
		x = temp;
		inter++;
	}
	return (inter);
}

void	my_mlx_mandel_put(t_mandel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
