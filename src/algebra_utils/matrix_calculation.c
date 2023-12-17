// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   matrix_calculation.c                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/14 19:09:48 by tzanchi           #+#    #+#             */
// /*   Updated: 2023/12/16 21:07:51 by helauren         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../inc/algebra.h"

// t_vec3	vec_add(t_vec3 A, t_vec3 B)
// {
// 	t_vec3	output;

// 	output.x = A.x + B.x;
// 	output.y = A.y + B.y;
// 	output.z = A.z + B.z;
// 	return (output);
// }

// t_vec3	vec_sub(t_vec3 A, t_vec3 B)
// {
// 	t_vec3	output;

// 	output.x = A.x - B.x;
// 	output.y = A.y - B.y;
// 	output.z = A.z - B.z;
// 	return (output);
// }

// t_vec3	vec_mul(t_vec3 A, t_vec3 B)
// {
// 	t_vec3	output;

// 	output.x = A.x * B.x;
// 	output.y = A.y * B.y;
// 	output.z = A.z * B.z;
// 	return (output);
// }

// float	dot_product(t_vec3 A, t_vec3 B)
// {
// 	return (A.x * B.x + A.y * B.y + A.z * B.z);
// }

// t_vec3	vec_mul_scalar(t_vec3 v, float t)
// {
// 	v.x *= t;
// 	v.y *= t;
// 	v.z *= t;
// 	return (v);
// }

// t_vec3	vec_normalize(t_vec3 v)
// {
// 	float length;
	
// 	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
//     if (length)
//     {
//         v.x /= length;
//         v.y /= length;
//         v.z /= length;
//     }
// 	return (v);
// }
