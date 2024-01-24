/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:27:59 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 19:39:22 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

t_vec3	set_straight(t_vec3 start, double vec_z)
{
	t_vec3	straight;

	straight.x = start.x;
	straight.y = start.y;
	if (vec_z > 0)
		straight.z = start.z + 1;
	else
		straight.z = start.z - 1;
	return (straight);
}

t_vec3	set_x_axis(t_vec3 start, double vec_x)
{
	t_vec3	x_axis;

	x_axis.z = start.z;
	x_axis.y = start.y;
	if (vec_x > 0)
		x_axis.x = start.x + 1;
	else
		x_axis.x = start.x - 1;
	return (x_axis);
}

t_vec3	set_y_axis(t_vec3 start, double vec_y)
{
	t_vec3	y_axis;

	y_axis.z = start.z;
	y_axis.x = start.x;
	if (vec_y > 0)
		y_axis.y = start.y + 1;
	else
		y_axis.y = start.y - 1;
	return (y_axis);
}

// double	get_vp_center_y(t_vec3 straight, t_vec3 y_axis, double cut)
// {
// 	t_vec3	vector;
// 	double	len;

// 	vector = findVector_3d(straight, y_axis);
// 	len = calculate_distance(straight, y_axis);
// 	if(cut < 0)
// 		cut = -cut;
// 	return (straight.y + (cut * len * vector.y));
// }

// double	get_vp_center_x(t_vec3 straight, t_vec3 x_axis, double cut)
// {
// 	t_vec3	vector;
// 	double	len;

// 	vector = findVector_3d(straight, x_axis);
// 	len = calculate_distance(straight, x_axis);
// 	if(cut < 0)
// 		cut = -cut;
// 	return (straight.x + (cut * len * vector.x));
// }

void	point_on_line(t_vec3 start, t_vec3 *end, t_vec3 len)
{
	t_vec3	vector;
	double	distance;

	vector = vec_sub(start, *end);
	distance = vec_len(vector);
	end->x = start.x + (len.x * distance * vector.x);
	end->y = start.y + (len.y * distance * vector.y);
	end->z = start.z + (len.z * distance * vector.z);
}

t_vec3	*viewport_center(t_data *data, t_vec3 start_pos)
{
	t_vec3	*center_vp;
	t_vec3	straight;
	t_vec3	x_axis;
	t_vec3	y_axis;

	center_vp = malloc(sizeof(t_vec3));
	straight = set_straight(start_pos, data->camera->vector.z);
	x_axis = set_x_axis(start_pos, data->camera->vector.x);
	y_axis = set_y_axis(start_pos, data->camera->vector.y);
	center_vp->x = x_axis.x;
	center_vp->y = x_axis.y;
	center_vp->z = start_pos.z;
	point_on_line(straight, center_vp, data->camera->vector);
	return (center_vp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:27:59 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 18:46:09 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

t_vec3	set_straight(t_vec3 start, double vec_z)
{
	t_vec3	straight;

	straight.x = start.x;
	straight.y = start.y;
	if(vec_z > 0)
		straight.z = start.z + 1;
	else
		straight.z = start.z - 1;
	return (straight);
}

t_vec3	set_x_axis(t_vec3 start, double vec_x)
{
	t_vec3	x_axis;

	(void) vec_x;
	x_axis.z = start.z;
	x_axis.y = start.y;
	// if(vec_x > 0)
	// else
	// 	x_axis.x = start.x - 1;
	x_axis.x = start.x + 1;
	return (x_axis);
}

t_vec3	set_y_axis(t_vec3 start, double vec_y)
{
	t_vec3	y_axis;

	(void) vec_y;
	y_axis.z = start.z;
	y_axis.x = start.x;
	// if(vec_y > 0)
	// else
	// 	y_axis.y = start.y - 1;
	y_axis.y = start.y + 1;
	return (y_axis);
}

// double	get_vp_center_y(t_vec3 straight, t_vec3 y_axis, double cut)
// {
// 	t_vec3	vector;
// 	double	len;

// 	vector = findVector_3d(straight, y_axis);
// 	len = calculate_distance(straight, y_axis);
// 	if(cut < 0)
// 		cut = -cut;
// 	return (straight.y + (cut * len * vector.y));
// }

// double	get_vp_center_x(t_vec3 straight, t_vec3 x_axis, double cut)
// {
// 	t_vec3	vector;
// 	double	len;

// 	vector = findVector_3d(straight, x_axis);
// 	len = calculate_distance(straight, x_axis);
// 	if(cut < 0)
// 		cut = -cut;
// 	return (straight.x + (cut * len * vector.x));
// }

void	point_on_line(t_vec3 start, t_vec3 *end, t_vec3 len)
{
	t_vec3	vector;
	double	distance;

	vector = findVector_3d(start, *end);
	distance = calculate_distance(start, *end);
	end->x = start.x + (len.x * distance * vector.x);
	end->y = start.y + (len.y * distance * vector.y);
	end->z = start.z + (len.z * distance * vector.z);
}

t_vec3	*viewport_center(t_data *data, t_vec3 start_pos)
{
	t_vec3	*center_vp;
	t_vec3	straight;
	t_vec3	x_axis;
	t_vec3	y_axis;

	center_vp = malloc(sizeof(t_vec3));
	straight = set_straight(start_pos, data->camera->vector.z);
	x_axis = set_x_axis(start_pos, data->camera->vector.x);
	y_axis = set_y_axis(start_pos, data->camera->vector.y);
	center_vp->x = x_axis.x;
	center_vp->y = x_axis.y;
	center_vp->z = start_pos.z;
	point_on_line(straight, center_vp, data->camera->vector);
	return (center_vp);
}
