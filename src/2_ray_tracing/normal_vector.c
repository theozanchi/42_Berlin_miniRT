/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:08:25 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/24 19:38:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

/**
 * @brief Calculate a normal vector from origin `hit_point` and with direction
 * `hit_point - sph->pos`
 * 
 */
t_vec3	sph_nor_vec3(t_point3 hit_point, t_o_sp *sph)
{
	return (normalize(vec_sub(hit_point, sph->pos)));
}

t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl)
{
	t_vec3	pc;
	t_vec3	n;

	pc = vec_sub(hit_point, cyl->pos);
	n = vec_sub(pc, mul_scalar(cyl->vector, dot(pc, cyl->vector)));
	return (n);
}

t_vec3	pla_nor_vec3(t_o_pl *pla, t_ray *ray)
{
	if (dot(*ray->direction, pla->vector) > 0)
		return (neg(pla->vector));
	else
		return (pla->vector);
}

/**
 * @brief Calculate a normal vector from `hit_point` to the `hit_obj` object
 * 
 */
t_vec3	normal_vec3(t_point3 hit_point, t_object *hit_obj, t_ray *ray)
{
	if (hit_obj->id == SPHERE)
		return (sph_nor_vec3(hit_point, (t_o_sp *)hit_obj));
	else if (hit_obj->id == CYLINDER)
		return (cyl_nor_vec3(hit_point, (t_o_cy *)hit_obj));
	else if (hit_obj->id == PLANE)
		return (pla_nor_vec3((t_o_pl *)hit_obj, ray));
	else
		return (vec(-1.0, -1.0, -1.0));
}
