/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_amount_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:07 by helauren          #+#    #+#             */
/*   Updated: 2024/01/23 19:09:04 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	iterate_rgb_ints(char *red, int i)
{
	int 	count;
	int	num;

	count = 0;
	count = count_ints(red, i);
	if(count != 3)
		return (-1);
	count = 0;
	while(count < 3)
	{
		i = next_float_index(red, i);
		num = ft_atoi(&red[i]);
		if(num < (double)0 || num > (double)255)
			return (-1);
		count++;
	}
	return (i);
}

int	iterate_three_floats(char *red, int i)
{
	int 	count;
	double	num;

	count = 0;
	while(count < 3)
	{
		i = next_float_index(red, i);
		if(i < 0)
			return (-1);
		num = get_double(&red[i]);
		count++;
	}
	return (i);
}

int	iterate_three_one_floats(char *red, int i)
{
	int 	count;
	double	num;

	count = 0;
	while(count < 3)
	{
		i = next_float_index(red, i);
		if(i < 0)
			return (-1);
		num = get_double(&red[i]);
		if(is_between_one(num))
			return (-1);
		count++;
	}
	return (i);
}

int	is_between_one(double num)
{
	if (num < (double)-1.0 || num > (double)1.0)
		return (1);
	return (0);
}

int	move_up_three(char *red, int i)
{
	int	count;

	count = 0;
	while(count < 3)
	{
		i = next_float_index(red, i);
		count++;
	}
	return (i);
}
