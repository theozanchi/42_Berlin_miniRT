/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:08:25 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/08 16:21:14 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

/**
 * @brief Calculate a normal vector from origin `hit_point` and with direction
 * `hit_point - sph->pos`
 * 
 */

t_vec3	sph_nor_vec3(t_point3 hit_point, t_o_sp *sph)
{
	return (unit_vec3(hit_point.x - sph->pos.x, hit_point.y - sph->pos.y,
			hit_point.z - sph->pos.z));
}

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
	if(hit_largeur(hit_point, cyl))
		return (cyl->vec_largeur);
	return (cyl->vec_largeur);
}

t_vec3	pla_nor_vec3(t_point3 hit_point, t_o_pl *pla)
{
	(void)hit_point;
	(void)pla;
	return (unit_vec3(1.0, 1.0, 1.0));
}

/**
 * @brief Calculate a normal vector from `hit_point` to the `hitted` object
 * 
 */
t_vec3	normal_vec3(t_point3 hit_point, t_object *hitted)
{
	if (hitted->id == SPHERE)
		return (sph_nor_vec3(hit_point, (t_o_sp *)hitted));
	else if (hitted->id == CYLINDER)
		return (cyl_nor_vec3(hit_point, (t_o_cy *)hitted));
	else if (hitted->id == PLANE)
		return (pla_nor_vec3(hit_point, (t_o_pl *)hitted));
	else
		return (unit_vec3(-1.0, -1.0, -1.0));
}
