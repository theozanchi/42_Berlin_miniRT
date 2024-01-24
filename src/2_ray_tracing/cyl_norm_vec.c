/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_norm_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:56:24 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 19:20:28 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "minirt.h"

// double	distance_between_two_points(t_point3 p1, t_point3 p2)
// {
// 	double	len;

// 	len = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y))
// 			+ ((p2.z - p1.z) * (p2.z - p1.z)));
// 	return (len);
// }

// t_point3	rotate_point(t_point3 p, t_vec3 vec, double angle)
// {
// 	double	cos_theta;
// 	double	sin_theta;
// 	double	rotation_matrix[3][3];

// 	cos_theta = cos(angle);
// 	sin_theta = sin(angle);
// 	rotation_matrix[0][0] = cos_theta + vec.x * vec.x *(1 - cos_theta);
// 	rotation_matrix[0][1] = vec.x * vec.y * (1 - cos_theta) - vec.z * sin_theta;
// 	rotation_matrix[0][2] = vec.x * vec.z * (1 - cos_theta) - vec.y * sin_theta;
// 	rotation_matrix[1][0] = vec.y * vec.x * (1 - cos_theta) + vec.z * sin_theta;
// 	rotation_matrix[1][1] = cos_theta + vec.y * vec.y *(1 - cos_theta);
// 	rotation_matrix[1][2] = vec.y * vec.z * (1 - cos_theta) - vec.x * sin_theta;
// 	rotation_matrix[2][0] = vec.z * vec.x * (1 - cos_theta) - vec.y * sin_theta;
// 	rotation_matrix[2][1] = vec.z * vec.y * (1 - cos_theta) + vec.x * sin_theta;
// 	rotation_matrix[2][2] = cos_theta + vec.z * vec.z * (1 - cos_theta);
// 	p.x = rotation_matrix[0][0] * p.x + rotation_matrix[0][1] * p.y + rotation_matrix[0][2] * p.z;
// 	p.y = rotation_matrix[1][0] * p.x + rotation_matrix[1][1] * p.y + rotation_matrix[1][2] * p.z;
// 	p.x = rotation_matrix[2][0] * p.x + rotation_matrix[2][1] * p.y + rotation_matrix[2][2] * p.z;
// 	return (p);
// }

// t_point3	find_d(t_point3 c, t_o_cy *cyl, double angle)
// {
// 	t_point3	top;
// 	t_point3	d;

// 	top = rotate_point(cyl->top, cyl->vector, angle);
// 	d = top;
// 	d.y = c.y;
// 	return (d);
// }

// t_vec3	hit_side(t_point3 hit_point, t_o_cy *cyl, double angle)
// {
// 	t_point3	c;
// 	t_point3	d;
// 	t_point3	ret;

// 	c = rotate_point(hit_point, cyl->vector, angle);
// 	d = find_d(c, cyl, angle);
// 	ret.x = c.x - d.x;
// 	ret.y = c.y - d.y;
// 	ret.z = c.z - d.z;
// 	return (ret);
// }

// t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl)
// {
// 	double	angle;
// 	t_point3	c;
// 	t_point3	top_no_vec;
// 	t_point3	ret;

// 	angle = acos((cyl->vector.x * 0 + cyl->vector.y * 0 + cyl->vector.z * 1) /
// 		sqrt((cyl->vector.x * cyl->vector.x) + (cyl->vector.y * cyl->vector.y) + (cyl->vector.z * cyl->vector.z)));
// 	c = rotate_point(hit_point, cyl->vector, angle);
// 	top_no_vec = rotate_point(cyl->top, cyl->vector, angle);
// 	if (c.x == top_no_vec.x && (distance_between_two_points(c,
// 				top_no_vec) <= cyl->diameter))
// 		ret = hit_side(hit_point, cyl, angle);
// 	else
// 		ret = cyl->vector;
// 	return (ret);
// }

// int	is_on_line(t_point3 center, t_vec3 vector, double len,
		// t_point3 hit_point)
// {
// 	double		distance;
// 	t_point3	test_point;

// 	distance = distance_between_two_points(center, hit_point);
// 	if (distance > len)
// 		return (0);
// 	test_point.x = center.x + (vector.x * distance);
// 	test_point.y = center.y + (vector.y * distance);
// 	test_point.z = center.z + (vector.z * distance);
// 	if(test_point.x == hit_point.x && test_point.y == hit_point.y
		// && test_point.z == hit_point.z)
// 		return (1);
// 	test_point.x = center.x + ((vector.x * distance) * -1);
// 	test_point.y = center.y + ((vector.y * distance) * -1);
// 	test_point.z = center.z + ((vector.z * distance) * -1);
// 	if(test_point.x == hit_point.x && test_point.y == hit_point.y
		// && test_point.z == hit_point.z)
// 		return (1);
// 	return (0);
// }

// int	hit_largeur(t_point3 hit_point, t_o_cy *cyl)
// {
// 	if(is_on_line(cyl->bottom, cyl->vector, cyl->diameter, hit_point)
// 		|| is_on_line(cyl->top, cyl->vector, cyl->diameter, hit_point))
// 		return (1);
// 	return (0);
// }

// t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl)
// {
// 	if(hit_largeur(hit_point, cyl) == 1)
// 		return (cyl->vec_hauteur);
// 	return (cyl->vec_largeur);
// }
