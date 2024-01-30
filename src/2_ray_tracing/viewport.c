/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:01:36 by helauren          #+#    #+#             */
/*   Updated: 2024/01/30 14:55:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

void	viewport_local_vectors_and_height(t_data *data)
{
	t_vec3	up_vec;

	up_vec.x = 0;
	up_vec.y = 1;
	up_vec.z = 0;
	if (equal(up_vec, data->camera->vector)
		|| equal(neg(up_vec), data->camera->vector))
		up_vec = vec(0, 0, 1);
	data->vp->local_right = prod(up_vec, data->camera->vector);
	data->vp->local_up = prod(data->vp->local_right, data->camera->vector);
	data->vp->local_down = data->vp->local_up;
	data->vp->local_up = neg(data->vp->local_up);
	data->vp->local_right = normalize(data->vp->local_right);
	data->vp->local_up = normalize(data->vp->local_up);
	data->vp->width = data->vp->aigu * 2;
	data->vp->height = (((double)HEIGTH / (double)WIDTH) * data->vp->width);
}

t_vec3	find_top_left_ray(t_data *data, t_vec3 center)
{
	t_vec3	top_left;
	double	len_right;
	double	len_bottom;

	len_right = (data->vp->width / (double)2);
	len_bottom = (data->vp->height / (double)2);
	top_left = center;
	top_left = vec_sub(top_left, vec_multiplier(data->vp->local_right,
				data->vp->width / 2));
	top_left = point_travel_by_vec_and_length(top_left, data->vp->local_up,
			len_bottom);
	return (top_left);
}

void	set_vector(double *arr, t_pdp var, t_data *data, t_vec3 top_left)
{
	t_vec3	right;
	t_vec3	point;
	t_vec3	vector;

	right = normalize(data->vp->local_right);
	point = point_travel_by_vec_and_length(top_left, right, var.distance_x);
	point = point_travel_by_vec_and_length(point, data->vp->local_down,
			var.distance_y);
	arr[0] = point.x;
	arr[1] = point.y;
	arr[2] = point.z;
	vector = unit_vec(arr[0] - data->camera->pos.x, arr[1]
			- data->camera->pos.y, arr[2] - data->camera->pos.z);
	arr[3] = vector.x;
	arr[4] = vector.y;
	arr[5] = vector.z;
}

double	***parse_dem_points(t_data *data, t_vec3 top_left)
{
	double	***ret;
	t_pdp	var;

	ret = malloc(sizeof(double **) * WIDTH);
	var.x = 0;
	var.distance_x = 0;
	while (var.x < WIDTH)
	{
		ret[var.x] = malloc(sizeof(double *) * HEIGTH);
		var.y = 0;
		var.distance_y = 0;
		while (var.y < HEIGTH)
		{
			ret[var.x][var.y] = malloc(sizeof(double) * 6);
			set_vector(ret[var.x][var.y], var, data, top_left);
			var.y++;
			var.distance_y = var.distance_y + data->vp->height / (double)HEIGTH;
		}
		var.distance_x = var.distance_x + data->vp->width / (double)WIDTH;
		var.x++;
	}
	return (ret);
}

void	viewport(t_data *data)
{
	t_vec3	center;
	t_vec3	top_left;

	data->vp = malloc(sizeof(t_vp));
	center = vec_add(data->camera->pos, normalize(data->camera->vector));
	viewport_trigo(data);
	viewport_local_vectors_and_height(data);
	top_left = find_top_left_ray(data, center);
	data->vp->points = parse_dem_points(data, top_left);
	if (DEBUG_VIEWPORT)
	{
		output_local_vectors(data->vp->points);
		output_viewport(data->vp->points);
	}
}
