/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:19:13 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 15:13:54 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_controls(void)
{
	ft_putstr("\n\033[1;33m***************  controls    ***************\n\n");
	ft_putstr("keys  | ************ Definitions ************\n");
	ft_putstr("---------------------------------------------\n");
	ft_putstr("Z     | *********  iteration = 1000  ********\n");
	ft_putstr("X     | *********** iteration = 10 **********\n");
	ft_putstr("E     | *********** iteration + 2  **********\n");
	ft_putstr("R     | *********** iteration - 2  **********\n");
	ft_putstr("C     | ** changing shaps (only for julia) **\n");
	ft_putstr("space | ********** changing colors **********\n");
	ft_putstr("\u2190 / A | ********** move left **********\n");
	ft_putstr("\u2191 / W | ********** move up **********\n");
	ft_putstr("\u2192 / D | ********** move right **********\n");
	ft_putstr("\u2193 / S | ********** move down **********\033[0m\n");
}

void	ft_instractions(void)
{
	ft_putstr("\033[1;33m./fractol \033[1;31m<Name>\033[0m \tOR");
	ft_putstr("\t\033[1;33m./fractol \033[1;31m<Name> \033[1;32m<Height>");
	ft_putstr("\033[1;35m<Width> \033[1;36m<Max Iteration>\033[0m\n\n");
	ft_putstr("\033[1;31m************************************\n");
	ft_putstr("*  Name :                          *\n");
	ft_putstr("*  - Mandelbrot OR m               *\n");
	ft_putstr("*  - Julia OR j                    *\n");
	ft_putstr("*  - Burn OR b                     *\n");
	ft_putstr("************************************\n");
	ft_putstr("\033[1;32m************************************\n");
	ft_putstr("*  Exemple of Height :             *\n");
	ft_putstr("*  - h650                          *\n");
	ft_putstr("*  - h300                          *\n");
	ft_putstr("************************************\n");
	ft_putstr("\033[1;35m************************************\n");
	ft_putstr("*  Exemple of Width :              *\n");
	ft_putstr("*  - w650                          *\n");
	ft_putstr("*  - w300                          *\n");
	ft_putstr("************************************\n");
	ft_putstr("\033[1;36m************************************\n");
	ft_putstr("*  Exemple of Max Iteration :      *\n");
	ft_putstr("*  - 10                            *\n");
	ft_putstr("*  - 1000                          *\n");
	ft_putstr("************************************\n");
}

void	ft_error(void)
{
	ft_putstr("\033[1;31m ******************************************");
	ft_putstr("***********\v*\r*\n");
	ft_putstr("* Wrong input, please follow this instruction bellow: *\n*");
	ft_putstr("\t\t\t\t\t\t      *\n");
	ft_putstr("\033[1;31m ******************************************");
	ft_putstr("***********\n\n");
	ft_instractions();
	ft_controls();
}
