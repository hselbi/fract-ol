/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:46:15 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/24 23:56:16 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	j = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while ((str1[i] || str2[i]) && n > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	rest;

	i = 0;
	sign = 1;
	rest = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + (str[i++] - '0');
		if (rest > LLONG_MAX && sign == 1)
			return (0);
		if (rest > LLONG_MAX && sign == -1)
			return (1);
	}
	return (rest * sign);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
