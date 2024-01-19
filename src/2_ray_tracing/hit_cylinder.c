/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:37:36 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/19 10:40:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

double	hit_cyl_tube(t_o_cy *cyl, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec_sub(*ray->origin, cyl->pos);
	a = dot2(*ray->direction) - square(dot(*ray->direction, cyl->vector));
	half_b = dot(*ray->direction, oc) - dot(*ray->direction, cyl->vector) 
		* dot(oc, cyl->vector);
	c = dot2(oc) - square(dot(oc, cyl->vector))
		- cyl->diameter * cyl->diameter / 4;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

// double	hit_cyl_caps(t_o_cy *cyl, t_ray *ray)
// {
// 	t_o_pl	top_plane;
// 	t_o_pl	bottom_plane;
// 	double	t;
// 	double	dis_to_center;

// 	{
// 		top_plane.rgb = cyl->rgb;
// 		top_plane.pos = cyl->top;
// 		top_plane.vector = cyl->vector;
// 		t = hit_plane(&top_plane, ray, NULL);
// 		dis_to_center = vec_len(vec_sub(point_on_ray(ray, t), cyl->top));
// 		if (t > 0.0 && dis_to_center <= cyl->diameter / 2)
// 			return (t);
// 	}
// 	{
// 		bottom_plane.rgb = cyl->rgb;
// 		bottom_plane.pos = cyl->bottom;
// 		bottom_plane.vector = neg(cyl->vector);
// 		t = hit_plane(&bottom_plane, ray, NULL);
// 		dis_to_center = vec_len(vec_sub(point_on_ray(ray, t), cyl->bottom));
// 		if (t > 0.0 && dis_to_center <= cyl->diameter / 2)
// 			return (t);
// 	}
// 	return (-1.0);
// }

/**
 * @brief Checks if `ray` hits the `cylinder`. If it is, `hit_obj` is updated
 * with the address of `cylinder`
 *
 * @param cylinder Pointer to the object
 * @param ray Pointer to the object
 * @param hit_obj Pointer to update
 * @return `t` (double), the distance from the ray origin if `cylinder` is hit,
 * -1.0 if `cylinder` is not hit
 */
double	hit_cylinder(t_o_cy *cyl, t_ray *ray, t_object ***hit_obj)
{
	double	t;
	t_vec3	oc;
	double	m;

	t = hit_cyl_tube(cyl, ray);
	if (t < 0.0)
	{
		// t = hit_cyl_caps(cyl, ray);
		// if (t > 0.0 && hit_obj)
		// 	**hit_obj = (t_object *)cyl;
		// else if (hit_obj)
		if (hit_obj)
			**hit_obj = NULL;
		return (t);
	}
	oc = vec_sub(*ray->origin, cyl->pos);
	m = dot(*ray->direction, cyl->vector) * t + dot(oc, cyl->vector);
	if (m < 0.0 || m > cyl->height)
		return (-1.0);
	else
	{
		if (hit_obj)
			**hit_obj = (t_object *)cyl;
		return (t);
	}
}
