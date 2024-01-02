/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:08:25 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/02 15:10:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

t_vec3	sph_nor_vec3(t_point3 hit_point, t_o_sp *sph)
{
	return (unit_vec3(hit_point.x - sph->pos.x, hit_point.y - sph->pos.y,
		hit_point.z - sph->pos.z));
}

t_vec3	cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl)
{
	(void)hit_point;
	(void)cyl;
	return (unit_vec3(1.0, 1.0, 1.0));
}

t_vec3	pla_nor_vec3(t_point3 hit_point, t_o_pl *pla)
{
	(void)hit_point;
	(void)pla;
	return (unit_vec3(1.0, 1.0, 1.0));
}

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
