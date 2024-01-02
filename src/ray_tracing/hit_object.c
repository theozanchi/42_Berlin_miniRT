/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:42:01 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/02 14:54:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

t_vec3	hit_point(t_data *data, int x, int y, double t)
{
	t_point3	point;

	point.x = data->vp->points[x][y][0] + t * data->vp->points[x][y][3];
	point.y = data->vp->points[x][y][1] + t * data->vp->points[x][y][4];
	point.z = data->vp->points[x][y][2] + t * data->vp->points[x][y][5];
	return (point);
}

t_point3	hit_sphere(t_o_sp *sphere, t_data *data, int x, int y, t_object ***hitted)
{
	double	oc[3];
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc[0] = data->vp->points[x][y][0] - sphere->pos.x;
	oc[1] = data->vp->points[x][y][1] - sphere->pos.y;
	oc[2] = data->vp->points[x][y][2] - sphere->pos.z;
	a = data->vp->points[x][y][3] * data->vp->points[x][y][3]
		+ data->vp->points[x][y][4] * data->vp->points[x][y][4]
		+ data->vp->points[x][y][5] * data->vp->points[x][y][5];
	half_b = (oc[0] * data->vp->points[x][y][3]
			+ oc[1] * data->vp->points[x][y][4]
			+ oc[2] * data->vp->points[x][y][5]);
	c = oc[0] * oc[0] + oc[1] * oc[1] + oc[2] * oc[2]
		- sphere->diameter * sphere->diameter / 4;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
	{
		**hitted = NULL;
		return (vec3(-1.0, -1.0, -1.0));
	}
	else
	{
		**hitted = (t_object *)sphere;
		return (hit_point(data, x, y, (-half_b - sqrt(discriminant)) / a));
	}
}

t_point3	hit_cylinder(t_o_cy *cylinder, t_data *data, int x, int y, t_object ***hitted)
{
	(void)cylinder;
	(void)data;
	(void)x;
	(void)y;
	**hitted = (t_object *)cylinder;
	return (vec3(1.0, 1.0, 1.0));
}

t_point3	hit_plane(t_o_pl *plane, t_data *data, int x, int y, t_object ***hitted)
{
	(void)plane;
	(void)data;
	(void)x;
	(void)y;
	**hitted = (t_object *)plane;;
	return (vec3(1.0, 1.0, 1.0));
}

t_point3	hit_object(t_data *data, int x, int y, t_object **hitted)
{
	t_object	*hittables;
	t_point3	hit_point;
	
	hittables = data->first;
	while (hittables)
	{
		if (data->first->id == SPHERE)
			hit_point = hit_sphere((t_o_sp *)hittables, data, x, y, &hitted);
		else if (hittables->id == CYLINDER)
			hit_point = hit_cylinder((t_o_cy *)hittables, data, x, y, &hitted);
		else if (hittables->id == PLANE)
			hit_point = hit_plane((t_o_pl *)hittables, data, x, y, &hitted);
		else
			hit_point = vec3(-1.0, -1.0, -1.0);
		hittables = hittables->next;
	}
	return (hit_point);
}
