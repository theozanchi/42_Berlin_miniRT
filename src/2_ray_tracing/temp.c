/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:15:34 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/31 17:15:36 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

t_mtx33	transf_mtx(t_data *data)
{
	t_vec3	wld_up;
	t_vec3	cam_right;
	t_vec3	cam_up;
	t_mtx33	mtx;

	wld_up = vec(0, 1, 0);
	if (equal(wld_up, data->camera->vector)
		|| equal(neg(wld_up), data->camera->vector))
		wld_up = vec(0, 0, 1);
	cam_right = normalize(prod(wld_up, data->camera->vector));
	cam_up = normalize(prod(data->camera->vector, cam_right));
	mtx.c0 = cam_right;
	mtx.c1 = cam_up;
	mtx.c2 = data->camera->vector;
	return (mtx);
}

t_point3	pixel_to_coor(t_data *data, int x, int y)
{
	t_point3	point;
	double		fov_ratio;
	double		img_ratio;

	fov_ratio = tan(data->camera->fov / 2 * M_PI / 180);
	img_ratio = (double)WIDTH / (double)HEIGTH;
	point.x = (2 * ((x + 0.5) / (double)WIDTH) - 1) * fov_ratio * img_ratio;
	point.y = (1 - 2 * ((y + 0.5) / (double)HEIGTH)) * fov_ratio;
	point.z = 1;
	return (point);
}

void	create_ray(t_ray *ray, t_data *data, int x, int y)
{
	t_point3	point;

	ray->origin = &data->camera->pos;
	point = pixel_to_coor(data, x, y);
	point = mtx_vec_prod(transf_mtx(data), point);
	point = vec_add(point, data->camera->pos);
	ray->direction->x = point.x - data->camera->pos.x;
	ray->direction->y = point.y - data->camera->pos.y;
	ray->direction->z = point.z - data->camera->pos.z;
}