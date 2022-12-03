/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:44:47 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:44:35 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	burn_scheme(t_burn *vast, t_pxl *pxl)
{
	double	temp;
	double	x;
	double	y;
	int		iter;

	iter = 0;
	x = 0;
	y = 0;
	while (fabs(x * x) + fabs(y * y) < 4 && iter < vast->max_inter)
	{
		temp = fabs(x * x) - fabs(y * y) + pxl->x;
		y = fabs(2 * x * y) + pxl->y;
		x = temp;
		iter++;
	}
	return (iter);
}

void	my_mlx_burn_put(t_burn *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
