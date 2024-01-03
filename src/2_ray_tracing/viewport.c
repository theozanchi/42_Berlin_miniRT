/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:01:36 by helauren          #+#    #+#             */
/*   Updated: 2024/01/03 20:11:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

void	viewport_trigo(t_data *data)
{
	data->vp->trigo.angle_a = 90;
	data->vp->trigo.angle_b = data->camera->fov / 2;
	data->vp->trigo.angle_c = 180 - data->vp->trigo.angle_a
		- data->vp->trigo.angle_b;
	data->vp->trigo.rad_a = data->vp->trigo.angle_a * (PI / 180);
	data->vp->trigo.rad_b = data->vp->trigo.angle_b * (PI / 180);
	data->vp->trigo.rad_c = data->vp->trigo.angle_c * (PI / 180);
	data->vp->trigo.cote_ab = 1;
	data->vp->trigo.cote_bc = ((data->vp->trigo.cote_ab
				* sin(data->vp->trigo.rad_a)) / sin(data->vp->trigo.rad_c));
	data->vp->trigo.cote_ca = ((data->vp->trigo.cote_ab
				* sin(data->vp->trigo.rad_b)) / sin(data->vp->trigo.rad_c));
}

t_vec3	*viewport_center(t_data *data, t_vec3 start_pos)
{
	double	magnitude;
	t_vec3	*center_vp;

	center_vp = malloc(sizeof(center_vp));
	magnitude = sqrt(((data->camera->vector.x) * (data->camera->vector.x))
			+ ((data->camera->vector.y) * (data->camera->vector.y))
			+ ((data->camera->vector.z) * (data->camera->vector.z)));
	center_vp->x = start_pos.x + data->camera->vector.x / magnitude;
	center_vp->y = start_pos.y + data->camera->vector.y / magnitude;
	center_vp->z = start_pos.z + data->camera->vector.z / magnitude;
	printf("center x = %f, start pos x = %f, cam vector x = %f, magnitude = %f\
		\n", center_vp->x, start_pos.x, data->camera->vector.x, magnitude);
	printf("center y = %f, start pos y = %f, cam vector y = %f, magnitude = %f\
		\n", center_vp->y, start_pos.y, data->camera->vector.y, magnitude);
	printf("center z = %f, start pos z = %f, cam vector z = %f, magnitude = %f\
		\n", center_vp->z, start_pos.z, data->camera->vector.z, magnitude);
	return (center_vp);
}

// double	CE;
// double	PE;
// double	rad;
// rad = 55 * ((double)M_PI * 180);
// CE = 1 * sin(rad); // length of CE
// PE = sqrt(1 + (CE * CE) - (2 * CE * cos(180 - 90 - data->camera->fov / 2)));
// 	// length of PE
// printf("length of PE = %f\n", PE);

double	longueur_hypothenuse(t_data *data)
{
	double	hypothenuse;
	double	rad;
	double	degrees;

	degrees = (double)(data->camera->fov / 2.0);
	// printf("FOV = %f, degrees = %f\n", (double)data->camera->FOV, degrees);
	rad = degrees * (M_PI / 180.0);
	// printf("rad = %f\n", rad);
	hypothenuse = 1.0 / cos(rad);
	// printf("hypothenuse = %f\n", hypothenuse);
	return (hypothenuse);
}

double	longueur_aigu(double hypothenuse)
{
	double	aigu;

	aigu = sqrt((hypothenuse * hypothenuse) - 1);
	return (aigu);
}

void	viewport_width(t_data *data, t_vec3 *center)
{
	double	hypothenuse;
	double	aigu;

	hypothenuse = longueur_hypothenuse(data);
	aigu = longueur_aigu(hypothenuse);
	printf("hypothenuse = %f, aigu = %f\n", hypothenuse, aigu);
	data->vp->min_x = center->x - aigu;
	data->vp->max_x = center->x + aigu;
	data->vp->min_y = center->y - aigu;
	data->vp->max_y = center->y + aigu;
	data->vp->width = data->vp->max_x - data->vp->min_x;
	data->vp->height = data->vp->max_y - data->vp->min_y;
}

void	set_vector(double *arr, t_data *data)
{
	arr[3] = arr[0] - data->camera->pos.x;
	arr[4] = arr[1] - data->camera->pos.y;
	arr[5] = arr[2] - data->camera->pos.z;
}

double	***parse_dem_points(t_data *data)
{
	double			***ret;
	unsigned int	x;
	unsigned int	y;
	double			pos_x_incr;
	double			pos_y_incr;
	double			pos_x;
	double			pos_y;

	printf("min x = %f\n", data->vp->min_x);
	printf("min y = %f\n", data->vp->min_y);
	ret = malloc(sizeof(double **) * data->window.width);
	pos_x_incr = ((double)data->vp->width) / (data->window.width - 1.0);
	pos_y_incr = ((double)data->vp->height) / (data->window.height - 1.0);
	printf("pos x incr = %f\n", pos_x_incr);
	printf("pos y incr = %f\n", pos_y_incr);
	x = 0;
	pos_x = 0;
	while(x < data->window.width)
	{
		ret[x] = malloc(sizeof(double *) * data->window.height);
		y = 0;
		pos_y = 0;
		while(y < data->window.height)
		{
			ret[x][y] = malloc(sizeof(double) * 6);
			ret[x][y][0] = data->vp->min_x + pos_x;
			ret[x][y][1] = data->vp->min_y + pos_y;
			ret[x][y][2] = data->camera->vector.z + data->camera->pos.z;
			set_vector(ret[x][y], data);
			y++;
			pos_y += pos_y_incr;
		}
		pos_x += pos_x_incr;
		x++;
	}
	return (ret);
}

void	viewport(t_data *data)
{
	t_vec3	*center;

	data->vp = malloc(sizeof(t_vp));
	center = viewport_center(data, data->camera->pos);
	viewport_trigo(data);
	viewport_width(data, center);
	data->vp->points = parse_dem_points(data);
	printf("min x = %f, max x = %f\n", data->vp->min_x, data->vp->max_x);
	printf("min y = %f, max y = %f\n", data->vp->min_y, data->vp->max_y);
	free(center);
	// output_viewport(data->vp->points, data);
}

// void	viewport_left(t_data *data, t_vec3 *P)
// {
// 	// double	CE;
// 	// double	PE;
// 	double	rad;
// 	t_vec3	vec_pc;
// 	t_vec3	unit_vector_pc;
// 	double	magnitude_pc;
// 	// t_vec3	vec_pe;

// 	// CE = 1 * sin(rad); // length of CE
// 	// PE = sqrt(1 + (CE * CE) - (2 * (CE) * cos(180 - 90 - data->camera->FOV / 2))); // length of PE
// 	vec_pc.x = -data->camera->vector.x;
// 	vec_pc.y = -data->camera->vector.y;
// 	vec_pc.z = -data->camera->vector.z;
// 	rad = 55 * ((double)M_PI * 180);
// 	magnitude_pc = sqrt(((data->camera->pos.x - P->x) * (data->camera->pos.x - P->x)) +
// 		((data->camera->pos.y - P->y) * (data->camera->pos.y - P->y)) +
// 		((data->camera->pos.z - P->z) * (data->camera->pos.z - P->z)));
// 	unit_vector_pc.x = (data->camera->pos.x - P->x) / magnitude_pc;
// 	unit_vector_pc.y = (data->camera->pos.x - P->x) / magnitude_pc;
// 	unit_vector_pc.z = (data->camera->pos.x - P->x) / magnitude_pc;
// }

// void	ray_after_ray(t_data *data)
// {
// 	unsigned int	x;
// 	unsigned int	y;
// 	double			rayon;
// 	double			z;

// 	z = data->camera->vector.z;
// 	rayon = (double)data->camera->FOV / 2;
// 	x = 0;
// 	while (x < data->window.width)
// 	{
// 		y = 0;
// 		while (y < data->window.height)
// 		{
// 			data->rays[x][y][0] = (double)x - (double)data->window.width / 2;
// 			data->rays[x][y][1] = (double)y - (double)data->window.height / 2;
// 			data->rays[x][y][2] = (double)z;
// 			y++;
// 		}
// 		x++;
// 	}
// 	output_ray_vectors(data);
// }
