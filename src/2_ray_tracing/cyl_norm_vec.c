/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_norm_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:56:24 by helauren          #+#    #+#             */
/*   Updated: 2024/01/08 20:25:29 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

double	distance_between_two_points(t_point3 p1, t_point3 p2)
{
	double	len;

	len = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y))
		+ ((p2.z - p1.z) * (p2.z - p1.z)));
	return (len);
}

int	is_on_line(t_point3 center, t_vec3 vector, double len, t_point3 hit_point)
{
	double		distance;
	t_point3	test_point;

	distance = distance_between_two_points(center, hit_point);
	if (distance > len)
		return (0);
	test_point.x = center.x + (vector.x * distance);
	test_point.y = center.y + (vector.y * distance);
	test_point.z = center.z + (vector.z * distance);
	if(test_point.x == hit_point.x && test_point.y == hit_point.y && test_point.z == hit_point.z)
		return (1);
	test_point.x = center.x + ((vector.x * distance) * -1);
	test_point.y = center.y + ((vector.y * distance) * -1);
	test_point.z = center.z + ((vector.z * distance) * -1);
	if(test_point.x == hit_point.x && test_point.y == hit_point.y && test_point.z == hit_point.z)
		return (1);
	return (0);
}

int	hit_largeur(t_point3 hit_point, t_o_cy *cyl)
{
	if(is_on_line(cyl->bottom, cyl->vector, cyl->diameter, hit_point)
		|| is_on_line(cyl->top, cyl->vector, cyl->diameter, hit_point))
		return (1);
	return (0);
}

t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl)
{
	if(hit_largeur(hit_point, cyl) == 1)
		return (cyl->vec_hauteur);
	return (cyl->vec_largeur);
}
