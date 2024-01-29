/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_amount_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:49:49 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 01:15:06 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	right_amount_a(char *red)
{
	int		count;
	int		i;
	double	num;

	i = 0;
	count = count_floats(red);
	i = next_float_index(red, i);
	num = get_double(&red[i]);
	if (count != 1 || num < (double)0.0 || num > (double)1.0)
		return (1);
	count = count_ints(red, i);
	if (count != 3)
		return (1);
	i = move_up_three(red, i);
	if (i < 0)
		return (1);
	if (empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_c(char *red)
{
	int	count;
	int	i;
	int	fov;

	count = count_floats(red);
	if (count != 3)
		return (1);
	i = move_up_three(red, 0);
	i = iterate_three_one_floats(red, i);
	i = next_float_index(red, i);
	if (i < 0)
		return (-1);
	fov = ft_atoi(&red[i]);
	if (fov < 0 || fov > 180)
		return (1);
	if (empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_l(char *red)
{
	int		count;
	int		i;
	double	num;

	count = count_floats(red);
	if (count != 3)
		return (1);
	i = move_up_three(red, 0);
	i = next_float_index(red, i);
	num = get_double(&red[i]);
	if (num < (double)0.0 || num > (double)1.0)
		return (1);
	count = count_ints(red, i);
	if (count != 3)
		return (1);
	i = move_up_three(red, i);
	if (i < 0)
		return (-1);
	if (empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_env(char *red)
{
	int	ret;

	ret = 0;
	if (red[0] == 'A')
		ret = right_amount_a(&red[1]);
	if (red[0] == 'C')
		ret = right_amount_c(&red[1]);
	if (red[0] == 'L')
		ret = right_amount_l(&red[1]);
	return (ret);
}
