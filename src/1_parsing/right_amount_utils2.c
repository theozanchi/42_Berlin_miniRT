/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_amount_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:07 by helauren          #+#    #+#             */
/*   Updated: 2024/01/16 20:52:18 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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
