// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   viewport_old.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/16 20:01:36 by helauren          #+#    #+#             */
// /*   Updated: 2024/01/25 19:36:29 by helauren         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../inc/minirt.h"
// #include "algebra.h"

// void	viewport_trigo(t_data *data)
// {
// 	data->vp->trigo.angle_a = 90;
// 	data->vp->trigo.angle_b = data->camera->fov / 2;
// 	data->vp->trigo.angle_c = 180 - data->vp->trigo.angle_a
// 		- data->vp->trigo.angle_b;
// 	data->vp->trigo.rad_a = data->vp->trigo.angle_a * (PI / 180);
// 	data->vp->trigo.rad_b = data->vp->trigo.angle_b * (PI / 180);
// 	data->vp->trigo.rad_c = data->vp->trigo.angle_c * (PI / 180);
// 	data->vp->trigo.cote_ab = 1;
// 	data->vp->trigo.cote_bc = ((data->vp->trigo.cote_ab
// 				* sin(data->vp->trigo.rad_a)) / sin(data->vp->trigo.rad_c));
// 	data->vp->trigo.cote_ca = ((data->vp->trigo.cote_ab
// 				* sin(data->vp->trigo.rad_b)) / sin(data->vp->trigo.rad_c));
// }

// double	longueur_hypothenuse(t_data *data)
// {
// 	double	hypothenuse;
// 	double	rad;
// 	double	degrees;

// 	degrees = (double)(data->camera->fov / 2.0);
// 	rad = degrees * (M_PI / 180.0);
// 	hypothenuse = 1.0 / cos(rad);
// 	return (hypothenuse);
// }

// double	longueur_aigu(double hypothenuse)
// {
// 	double	aigu;

// 	aigu = sqrt((hypothenuse * hypothenuse) - 1);
// 	return (aigu);
// }

// void	viewport_width(t_data *data, t_vec3 center)
// {
// 	double	hypothenuse;
// 	double	aigu;
// 	double	win_ratio;

// 	hypothenuse = longueur_hypothenuse(data);
// 	aigu = longueur_aigu(hypothenuse);
// 	win_ratio = (((double)HEIGTH / (double)WIDTH) * aigu);
// 	// printf("hypothenuse = %f, aigu = %f\n", hypothenuse, aigu);
// 	data->vp->min_x = center.x - aigu;
// 	data->vp->max_x = center.x + aigu;
// 	data->vp->min_y = center.y - win_ratio;
// 	data->vp->max_y = center.y + win_ratio;
// 	data->vp->width = data->vp->max_x - data->vp->min_x;
// 	data->vp->height = data->vp->max_y - data->vp->min_y;
// }

// void	set_vector(double *arr, t_data *data)
// {
// 	t_vec3	vector;
// 	static int	i = 0;

		
// 	// vector = calculate_vector(data->camera->pos, vector);
// 	// printf("vector x = %lf, vector y = %lf, vector z = %lf\n", vector.x, vector.y, vector.z);
// 	vector = unit_vec(arr[0] - data->camera->pos.x, arr[1] - data->camera->pos.y, arr[2] - data->camera->pos.z);
// 	arr[3] = vector.x;
// 	arr[4] = vector.y;
// 	arr[5] = vector.z;
// 	if (i == 0)
// 	{
// 		printf("cam vec z = %lf, cam pos z = %lf\n",data->camera->vector.z, data->camera->pos.z);
// 		printf("pos x = %lf, pos y = %lf, pos z = %lf\n", arr[0], arr[1], arr[2]);
// 		printf("vec x = %lf, vec y = %lf, vec z = %lf\n", arr[3], arr[4], arr[5]);
// 		i++;
// 	}
// 	vector = unit_vec(arr[3], arr[4], arr[5]);
// }

// double	***parse_dem_points(t_data *data)
// {
// 	double			***ret;
// 	unsigned int	x;
// 	unsigned int	y;
// 	double			pos_x_incr;
// 	double			pos_y_incr;
// 	double			pos_x;
// 	double			pos_y;

// 	// printf("min x = %f\n", data->vp->min_x);
// 	// printf("min y = %f\n", data->vp->min_y);
// 	// printf("max x = %f\n", data->vp->max_x);
// 	// printf("max y = %f\n", data->vp->max_y);
// 	ret = malloc(sizeof(double **) * WIDTH);
// 	pos_x_incr = ((double)data->vp->width) / ((double)WIDTH - 1.0);
// 	pos_y_incr = ((double)data->vp->height) / ((double)HEIGTH - 1.0);
// 	// printf("vp width = %f, WIDTH = %f, pos x incr = %f\n", data->vp->width, (double)WIDTH, pos_x_incr);
// 	// printf("vp height = %f, HEIGHT = %f, pos y incr = %f\n", data->vp->height, (double)HEIGTH, pos_y_incr);
// 	x = 0;
// 	pos_x = 0;
// 	while(x < WIDTH)
// 	{
// 		ret[x] = malloc(sizeof(double *) * HEIGTH);
// 		y = 0;
// 		pos_y = 0;
// 		while(y < HEIGTH)
// 		{
// 			ret[x][y] = malloc(sizeof(double) * 6);
// 			ret[x][y][0] = data->vp->min_x + pos_x;
// 			ret[x][y][1] = data->vp->max_y - pos_y;
// 			ret[x][y][2] = data->camera->vector.z + data->camera->pos.z;
// 			set_vector(ret[x][y], data);
// 			y++;
// 			pos_y += pos_y_incr;
// 		}
// 		pos_x += pos_x_incr;
// 		x++;
// 	}
// 	return (ret);
// }

// void	viewport(t_data *data)
// {
// 	t_vec3	center;

// 	data->vp = malloc(sizeof(t_vp));
// 	center = viewport_center(data, data->camera->pos);
// 	center = normalize(center);
// 	viewport_trigo(data);
// 	viewport_width(data, center);
// 	data->vp->points = parse_dem_points(data);
// 	output_local_vectors(data->vp->points);
// 	output_viewport(data->vp->points);
// }
