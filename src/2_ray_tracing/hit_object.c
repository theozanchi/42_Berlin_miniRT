/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:42:01 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/24 23:25:54 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "../../inc/minirt.h"

/**
 * @brief Checks if `ray` hits the `sphere`. If it is, `hit_obj` is updated with
 * the address of `sphere`
 *
 * @param sphere Pointer to the object
 * @param ray Pointer to the object
 * @param hit_obj Pointer to update
 * @return `t` (double), the distance from the ray origin if `sphere` is hit,
	-1.0
 * if `sphere` is not hit
 */
double	hit_sphere(t_o_sp *sphere, t_ray *ray, t_object ***hit_obj)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec_sub(*ray->origin, sphere->pos);
	a = dot2(*ray->direction);
	half_b = dot(oc, *ray->direction);
	c = dot2(oc) - sphere->diameter * sphere->diameter / 4;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
	{
		if (hit_obj)
			**hit_obj = NULL;
		return (-1.0);
	}
	else
	{
		if (hit_obj)
			**hit_obj = (t_object *)sphere;
		return ((-half_b - sqrt(discriminant)) / a);
	}
}

/**
 * @brief Checks if `ray` hits the `plane`. If it is, `hit_obj` is updated with
 * the address of `plane`
 *
 * @param plane Pointer to the object
 * @param ray Pointer to the object
 * @param hit_obj Pointer to update
 * @return `t` (double), the distance from the ray origin if `plane` is hit,
	-1.0
 * if `plane` is not hit
 */
double	hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hit_obj)
{
	t_vec3	oc;
	double	numerator;
	double	denominator;

	oc = vec_sub(*ray->origin, plane->pos);
	denominator = dot(*ray->direction, plane->vector);
	if (denominator == 0)
		return (-1.0);
	numerator = -1 * dot(oc, plane->vector);
	if (!same_sign_double(numerator, denominator))
		return (-1.0);
	if (hit_obj)
		**hit_obj = (t_object *)plane;
	return (numerator / denominator);
}

/**
 * @brief Get the distance t from the origin of `ray` where `object` is hit,
 * depending on `object` type
 *
 * @param object Pointer to the object
 * @param ray Pointer to the object
 * @param temp_hit_obj Pointer to update with the address of `object` if
 * `object` is hit by `ray`
 * @return `t` (double) or -1.0 if `object` is not hit by `ray`
 */
double	get_t(t_object *object, t_ray *ray, t_object **temp_hit_obj)
{
	double	t;

	if (object->id == SPHERE)
		t = hit_sphere((t_o_sp *)object, ray, &temp_hit_obj);
	else if (object->id == CYLINDER)
		t = hit_cylinder((t_o_cy *)object, ray, &temp_hit_obj);
	else
		t = hit_plane((t_o_pl *)object, ray, &temp_hit_obj);
	return (t);
}

/**
 * @brief Updates the pointer `hit_obj` with the closest obejct from
 * `ray->origin` hit by the ray and returns the distance from origin
 *
 * @param hittables List of all objects of the scene
 * @param ray Pointer to the current ray
 * @param hit_obj Pointer to update with the address of the closest hit object
 * @return `t` (double), the distance from the ray origin where the object is
 * hit
 */
double	hit_object(t_object *hittables, t_ray *ray, t_object **hit_obj)
{
	double		t;
	double		temp_t;
	t_object	*temp_hit_obj;

	t = -1.0;
	temp_hit_obj = NULL;
	while (hittables)
	{
		temp_t = get_t(hittables, ray, &temp_hit_obj);
		if ((t < 0 && temp_t > 0) || (temp_t > 0 && temp_t < t))
		{
			t = temp_t;
			if (hit_obj)
				*hit_obj = temp_hit_obj;
		}
		hittables = hittables->next;
	}
	return (t);
}
