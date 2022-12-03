/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:42:38 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:41:53 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0
			|| ft_strncmp(argv[1], "m", ft_strlen(argv[1])) == 0)
			size_check_mandel(argc, argv);
		else if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0
			|| ft_strncmp(argv[1], "j", ft_strlen(argv[1])) == 0)
			size_check_julia(argc, argv);
		else if (ft_strncmp(argv[1], "Burn", ft_strlen(argv[1])) == 0
			|| ft_strncmp(argv[1], "b", ft_strlen(argv[1])) == 0)
			size_check_burn(argc, argv);
	}
	ft_error();
	return (0);
}
