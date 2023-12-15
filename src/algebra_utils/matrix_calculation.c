/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:09:48 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/14 19:52:59 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/algebra.h"

t_vec3	vec_add(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x + B.x;
	output.y = A.y + B.y;
	output.z = A.z + B.z;
	return (output);
}

t_vec3	vec_sub(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x - B.x;
	output.y = A.y - B.y;
	output.z = A.z - B.z;
	return (output);
}

t_vec3	vec_mul(t_vec3 A, t_vec3 B)
{
	t_vec3	output;

	output.x = A.x * B.x;
	output.y = A.y * B.y;
	output.z = A.z * B.z;
	return (output);
}

float	dot_product(t_vec3 A, t_vec3 B)
{
	return (A.x * B.x + A.y * B.y + A.z * B.z);
}
