/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:08:25 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/14 16:06:23 by helauren         ###   ########.fr       */
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
	return (vec_normalize(vec_sub(hit_point, sph->pos)));
}

t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl, t_ray *ray, double t)
{
	t_vec3	oc;
	double	m;
	t_vec3	n;

	oc = vec_sub(*ray->origin, cyl->pos);
	m = dot(*ray->direction, vec_mul_scalar(cyl->vector, t))
		+ dot(oc, *ray->direction);
	n = vec_sub(hit_point, cyl->pos);
	n = vec_sub(n, vec_mul_scalar(cyl->vector, m));
	return (vec_normalize(n));
}

t_vec3	pla_nor_vec3(t_o_pl *pla, t_ray *ray)
{
	if (dot(*ray->direction, pla->vector) < 0)
		return (vec_mul_scalar(pla->vector, -1.0));
	else
		return (pla->vector);
}

/**
 * @brief Calculate a normal vector from `hit_point` to the `hitted` object
 * 
 */
t_vec3	normal_vec3(t_point3 hit_point, t_object *hitted, t_ray *ray, double t)
{
	(void)t;
	if (hitted->id == SPHERE)
		return (sph_nor_vec3(hit_point, (t_o_sp *)hitted));
	else if (hitted->id == CYLINDER)
	{
		// return (cyl_nor_vec3(hit_point, (t_o_cy *)hitted));
		return (cyl_nor_vec3(hit_point, (t_o_cy *)hitted, ray, t));
	}
	else if (hitted->id == PLANE)
		return (pla_nor_vec3((t_o_pl *)hitted, ray));
	else
		return (unit_vec3(-1.0, -1.0, -1.0));
}
