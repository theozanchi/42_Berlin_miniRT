/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:42:01 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 17:25:15 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

t_vec3	hit_point(t_ray *ray, double t)
{
	t_point3	point;

	point.x = ray->origin->x + t * ray->direction->x;
	point.y = ray->origin->y + t * ray->direction->y;
	point.z = ray->origin->z + t * ray->direction->z;
	return (point);
}

t_point3	hit_sphere(t_o_sp *sphere, t_ray *ray, t_object ***hitted)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec_sub(*ray->origin, sphere->pos);
	a = dot_product(*ray->direction, *ray->direction);
	half_b = dot_product(oc, *ray->direction);
	c = dot_product(oc, oc)	- sphere->diameter * sphere->diameter / 4;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
	{
		**hitted = NULL;
		return (vec3(-1.0, -1.0, -1.0));
	}
	else
	{
		**hitted = (t_object *)sphere;
		return (hit_point(ray, (-half_b - sqrt(discriminant)) / a));
	}
}

t_point3	hit_cylinder(t_o_cy *cylinder, t_ray *ray, t_object ***hitted)
{
	(void)cylinder;
	(void)ray;
	**hitted = (t_object *)cylinder;
	return (vec3(1.0, 1.0, 1.0));
}

t_point3	hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hitted)
{
	(void)plane;
	(void)ray;
	**hitted = (t_object *)plane;;
	return (vec3(1.0, 1.0, 1.0));
}

t_point3	hit_object(t_object *hittables, t_ray *ray, t_object **hitted)
{
	t_point3	hit_point;
	
	while (hittables)
	{
		if (hittables->id == SPHERE)
			hit_point = hit_sphere((t_o_sp *)hittables, ray, &hitted);
		else if (hittables->id == CYLINDER)
			hit_point = hit_cylinder((t_o_cy *)hittables, ray, &hitted);
		else if (hittables->id == PLANE)
			hit_point = hit_plane((t_o_pl *)hittables, ray, &hitted);
		else
			hit_point = vec3(-1.0, -1.0, -1.0);
		hittables = hittables->next;
	}
	return (hit_point);
}
