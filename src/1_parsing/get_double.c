/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:24:45 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 18:29:21 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	get_decimal(char *s, int i)
{
	double	a;
	double	div;
	double	ret;

	ret = 0;
	div = 10;
	while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
	{
		a = s[i] - '0';
		a = a / div;
		ret = ret + a;
		i++;
		div = div * 10;
	}
	return (ret);
}

int	handle_negative(int i, int *sign)
{
	*sign = -1;
	return (i +1);
}

double	get_double(char *s)
{
	double	ret;
	int		i;
	int		sign;
	double	dec;

	sign = 0;
	i = 0;
	if (s[i] == '-')
		i = handle_negative(i, &sign);
	ret = 0;
	while (ft_isdigit(s[i]))
	{
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	if (s[i] == '.')
		i++;
	dec = get_decimal(s, i);
	ret = ret + dec; 
	if (sign < 0)
		ret = -ret;
	return (ret);
}
