/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:37:36 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 20:52:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

typedef struct s_roots {
	double	root1;
	double	root2;
}	t_roots;

double	solve_cyl_quadratic(t_o_cy *cyl, t_ray *ray, t_vec3 oc)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

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

double	hit_cyl_tube(t_o_cy *cyl, t_ray *ray)
{
	t_vec3	oc;
	double	t;
	double	m;

	oc = vec_sub(*ray->origin, cyl->pos);
	t = solve_cyl_quadratic(cyl, ray, oc);
	if (t < 0.0)
		return (t);
	m = dot(*ray->direction, cyl->vector) * t + dot(oc, cyl->vector);
	if (m < 0 || m > cyl->height)
		return (-1.0);
	else
		return (t);
}

double	hit_cyl_cap(t_o_cy *cyl, t_ray *ray, enum e_side side)
{
	double	t;
	double	dis_to_center;

	if (side == TOP)
	{
		t = hit_plane(cyl->top_plane, ray, NULL);
		dis_to_center = vec_len(vec_sub(point_on_ray(ray, t), cyl->top_plane->pos));
		if (t > 0.0 && dis_to_center <= cyl->diameter / 2)
			return (t);
		else
			return (-1.0);
	}
	else
	{
		t = hit_plane(cyl->bottom_plane, ray, NULL);
		dis_to_center = vec_len(vec_sub(point_on_ray(ray, t), cyl->bottom_plane->pos));
		if (t > 0.0 && dis_to_center <= cyl->diameter / 2)
			return (t);
		else
			return (-1.0);
	}
}

double	hit_cylinder(t_o_cy *cyl, t_ray *ray, t_object ***hit_obj)
{
	double	t_tube;
	double	t_top;
	double	t_bottom;
	double	t;

	if (hit_obj)
		**hit_obj = NULL;
	t_tube = hit_cyl_tube(cyl, ray);
	t_top = hit_cyl_cap(cyl, ray, TOP);
	t_bottom = hit_cyl_cap(cyl, ray, BOTTOM);
	t = smallest_positive(3, t_tube, t_top, t_bottom);
	if (t > 0.0)
	{
		if (hit_obj)
		{
			if (t == t_tube)
				**hit_obj = (t_object *)cyl;
			else if (t == t_top)
				**hit_obj = (t_object *)cyl->top_plane;
			else
				**hit_obj = (t_object *)cyl->bottom_plane;
		}
	}
	return (t);
}
