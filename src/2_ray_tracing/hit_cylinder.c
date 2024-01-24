/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:37:36 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/24 19:35:57 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

typedef struct s_roots {
	double	r1;
	double	r2;
}	t_roots;

t_roots	solve_cyl_quadratic(t_o_cy *cyl, t_ray *ray, t_vec3 oc)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_roots	r;

	a = dot2(*ray->direction) - square(dot(*ray->direction, cyl->vector));
	half_b = dot(*ray->direction, oc) - dot(*ray->direction, cyl->vector) 
		* dot(oc, cyl->vector);
	c = dot2(oc) - square(dot(oc, cyl->vector))
		- cyl->diameter * cyl->diameter / 4;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
	{
		r.r1 = -1.0;
		r.r2 = -1.0;
		return (r);
	}
	else
	{
		r.r1 = (-half_b - sqrt(discriminant)) / a;
		r.r2 = (-half_b + sqrt(discriminant)) / a;
		return (r);
	}
}

double	hit_cyl_tube(t_o_cy *cyl, t_ray *ray)
{
	t_vec3	oc;
	t_roots	r;
	double	m1;
	double	m2;

	oc = vec_sub(*ray->origin, cyl->pos);
	r = solve_cyl_quadratic(cyl, ray, oc);
	if (r.r1 < 0.0 && r.r2 < 0.0)
		return (-1.0);
	m1 = dot(*ray->direction, cyl->vector) * r.r1 + dot(oc, cyl->vector);
	m2 = dot(*ray->direction, cyl->vector) * r.r2 + dot(oc, cyl->vector);
	if ((m1 >= cyl->height / -2 && m1 <= cyl->height / 2))
		return (ft_min_double(r.r1, r.r2));
	else if (m2 >= cyl->height / -2 && m2 <= cyl->height / 2)
		return (r.r2);
	else
		return (-1.0);
}

double	hit_cyl_cap(t_o_cy *cyl, t_ray *ray, enum e_side side)
{
	double	t;
	double	pc_len;

	if (side == TOP)
	{
		t = hit_plane(cyl->top_plane, ray, NULL);
		pc_len = vec_len(vec_sub(point_on_ray(ray, t), cyl->top_plane->pos));
		if (t > 0.0 && pc_len <= cyl->diameter / 2)
			return (t);
		else
			return (-1.0);
	}
	else
	{
		t = hit_plane(cyl->bottom_plane, ray, NULL);
		pc_len = vec_len(vec_sub(point_on_ray(ray, t), cyl->bottom_plane->pos));
		if (t > 0.0 && pc_len <= cyl->diameter / 2)
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
