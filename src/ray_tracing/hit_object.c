/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:42:01 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 18:53:57 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

t_point3	point_on_ray(t_ray *ray, double t)
{
	t_point3	point;

	point.x = ray->origin->x + t * ray->direction->x;
	point.y = ray->origin->y + t * ray->direction->y;
	point.z = ray->origin->z + t * ray->direction->z;
	return (point);
}

double	hit_sphere(t_o_sp *sphere, t_ray *ray, t_object ***hitted)
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
		return (-1.0);
	}
	else
	{
		**hitted = (t_object *)sphere;
		return ((-half_b - sqrt(discriminant)) / a);
	}
}

double	hit_cylinder(t_o_cy *cylinder, t_ray *ray, t_object ***hitted)
{
	(void)cylinder;
	(void)ray;
	**hitted = (t_object *)cylinder;
	return (1.0);
}

double	hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hitted)
{
	(void)plane;
	(void)ray;
	**hitted = (t_object *)plane;
	return (1.0);
}

double	get_t(t_object *hittables, t_ray *ray, t_object **temp_hitted)
{
	double		t;

	if (hittables->id == SPHERE)
		t = hit_sphere((t_o_sp *)hittables, ray, &temp_hitted);
	else if (hittables->id == CYLINDER)
		t = hit_cylinder((t_o_cy *)hittables, ray, &temp_hitted);
	else
		t = hit_plane((t_o_pl *)hittables, ray, &temp_hitted);
	return (t);
}

double	hit_object(t_object *hittables, t_ray *ray, t_object **hitted)
{
	double		t;
	double		temp_t;
	t_object	*temp_hitted;

	t = -1.0;
	temp_hitted = NULL;
	while (hittables)
	{
		temp_t = get_t(hittables, ray, &temp_hitted);
		if ((t < 0 && temp_t > 0) || (temp_t > 0 && temp_t < t))
		{
			t = temp_t;
			*hitted = temp_hitted;
		}
		hittables = hittables->next;
	}
	return (t);
}
