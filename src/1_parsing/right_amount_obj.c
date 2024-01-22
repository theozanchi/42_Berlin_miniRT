/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_amount_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:49:49 by helauren          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:22 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	right_amount_pl(char *red)
{
	int		count;
	int		i;
	double	num;

	count = count_floats(red);
	if(count != 3)
		return (1);
	i = move_up_three(red, 0);
	i = iterate_three_one_floats(red, i);
	count = 0;
	while(count < 3 && i >= 0)
	{
		i = next_float_index(red, i);
		num = ft_atoi(&red[i]);
		if(num < 0 || num > 255)
			return (1);
		count++;
	}
	if(i < 0)
		return (-1);
	if(empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_cy(char *red)
{
	int		count;
	int		i;
	double	num;

	count = count_floats(red);
	i = move_up_three(red, 0);
	if(count != 3 || i < 0)
		return (1);
	i = iterate_three_one_floats(red, i);
	i = next_float_index(red, i);
	num = get_double(&red[i]);
	if(num < (double)0.0)
		return (1);
	i = next_float_index(red, i);
	num = get_double(&red[i]);
	if(num < (double)0.0)
		return (1);
	i = iterate_rgb_ints(red, i);
	if(i < 0)
		return (-1);
	if(empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_sp(char *red)
{
	int		count;
	int		i;
	double	num;

	printf("sp start = %s\n", red);
	count = count_floats(red);
	if(count != 3)
		return (1);
	i = move_up_three(red, 0);
	i = next_float_index(red, i);
	num = get_double(&red[i]);
	if(num < (double)0.0)
		return (1);
	i = iterate_rgb_ints(red, i);
	if(i < 0)
		return (-1);
	if(empty_end(red, i))
		return (1);
	return (0);
}

int	right_amount_obj(char *red)
{
	int	ret;

	ret = 0;
	if (ft_strlen (red) < 3)
		return (ret);
	if (red[0] == 's' && red[1] == 'p')
		ret = right_amount_sp(&red[2]);
	if (red[0] == 'p' && red[1] == 'l')
		ret = right_amount_pl(&red[2]);
	if (red[0] == 'c' && red[1] == 'y')
		ret = right_amount_cy(&red[2]);
	return (ret);
}
