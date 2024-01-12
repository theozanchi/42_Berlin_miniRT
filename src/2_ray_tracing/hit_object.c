/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:42:01 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/12 15:07:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/algebra.h"
#include "../../inc/minirt.h"

/**
 * @brief Checks if `ray` hits the `sphere`. If it is, `hitted` is updated with
 * the address of `sphere`
 *
 * @param sphere Pointer to the object
 * @param ray Pointer to the object
 * @param hitted Pointer to update
 * @return `t` (double), the distance from the ray origin if `sphere` is hit,
	-1.0
 * if `sphere` is not hit
 */
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
	c = dot_product(oc, oc) - sphere->diameter * sphere->diameter / 4;
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

/**
 * @brief Checks if `ray` hits the `cylinder`. If it is, `hitted` is updated
 * with the address of `cylinder`
 *
 * @param cylinder Pointer to the object
 * @param ray Pointer to the object
 * @param hitted Pointer to update
 * @return `t` (double), the distance from the ray origin if `cylinder` is hit,
 * -1.0 if `cylinder` is not hit
 */
double	hit_cylinder(t_o_cy *cylinder, t_ray *ray, t_object ***hitted)
{
	(void)cylinder;
	(void)ray;
	**hitted = (t_object *)cylinder;
	return (1.0);
}

double	dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/**
 * @brief Checks if `ray` hits the `plane`. If it is, `hitted` is updated with
 * the address of `plane`
 *
 * @param plane Pointer to the object
 * @param ray Pointer to the object
 * @param hitted Pointer to update
 * @return `t` (double), the distance from the ray origin if `plane` is hit,
	-1.0
 * if `plane` is not hit
 */
double	hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hitted, t_o_c *cam)
{
	t_vec3	plane_to_ray_origin;
	double	denominator;
	double	t;

	denominator = dot(*ray->direction, plane->vector);
	if (fabs(denominator) > 1e-6)
	{
		plane_to_ray_origin.x = cam->pos.x - plane->pos.x;
		plane_to_ray_origin.y = cam->pos.y - plane->pos.y;
		plane_to_ray_origin.z = cam->pos.z - plane->pos.z;
		t = -dot(plane_to_ray_origin, plane->vector) / denominator;
		**hitted = (t_object *)plane;
		return (t);
	}
	return (-1.0);
}
// double	hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hitted)
// {
// 	double	points[3];

// 	**hitted = (t_object *)plane;
// 	return (1.0);
// }

/**
 * @brief Get the distance t from the origin of `ray` where `object` is hit,
 * depending on `object` type
 *
 * @param object Pointer to the object
 * @param ray Pointer to the object
 * @param temp_hitted Pointer to update with the address of `object` if `object`
 * is hit by `ray`
 * @return `t` (double) or -1.0 if `object` is not hit by `ray`
 */
double	get_t(t_object *object, t_ray *ray, t_object **temp_hitted, t_o_c *cam)
{
	double	t;

	if (object->id == SPHERE)
		t = hit_sphere((t_o_sp *)object, ray, &temp_hitted);
	else if (object->id == CYLINDER)
		t = hit_cylinder((t_o_cy *)object, ray, &temp_hitted);
	else
		t = hit_plane((t_o_pl *)object, ray, &temp_hitted, cam);
	return (t);
}

/**
 * @brief Updates the pointer `hitted` with the closest obejct from
 * `ray->origin` hitted by the ray and returns the distance from origin
 *
 * @param hittables List of all objects of the scene
 * @param ray Pointer to the current ray
 * @param hitted Pointer to update with the address of the closest hitted object
 * @return `t` (double), the distance from the ray origin where the object is
 * hit
 */
double	hit_object(t_object *hittables, t_ray *ray, t_object **hitted,
		t_data *data)
{
	double		t;
	double		temp_t;
	t_object	*temp_hitted;

	t = -1.0;
	temp_hitted = NULL;
	while (hittables)
	{
		temp_t = get_t(hittables, ray, &temp_hitted, data->camera);
		if ((t < 0 && temp_t > 0) || (temp_t > 0 && temp_t < t))
		{
			t = temp_t;
			*hitted = temp_hitted;
		}
		hittables = hittables->next;
	}
	return (t);
}
