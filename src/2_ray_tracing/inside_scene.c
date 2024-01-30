/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:59:51 by helauren          #+#    #+#             */
/*   Updated: 2024/01/30 09:57:05 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

t_object	*inside_sphere(t_data *data, t_o_sp *sp)
{
	t_vec3	cam_to_center;
	double	distance;

	cam_to_center = vec_sub(data->camera->pos, sp->pos);
	distance = vec_len(cam_to_center);
	if (distance <= sp->diameter / 2)
		return ((t_object *)sp);
	else
		return (NULL);
}

t_object	*inside_cylinder(t_data *data, t_o_cy *cy)
{
	t_vec3		cam_to_center;
	double		projection;
	t_point3	proj_point;
	double		distance_to_axis;

	cam_to_center = vec_sub(data->camera->pos, cy->pos);
	projection = dot(cam_to_center, cy->vector);
	proj_point = vec_sub(cy->pos, mul_scalar(cy->vector, projection));
	distance_to_axis = vec_len(vec_sub(data->camera->pos, proj_point));
	if (distance_to_axis <= cy->diameter / 2
		&& projection >= cy->height / -2 && projection <= cy->height / 2)
		return ((t_object *)cy);
	else
		return (NULL);	
}

t_object	*inside_object(t_data *data)
{
	t_object	*inside_this;
	t_object	*ptr;

	inside_this = NULL;
	if (data->obj_count == 0)
		return (NULL);
	ptr = data->first;
	while (ptr)
	{
		if (ptr->id == SPHERE)
			inside_this = inside_sphere(data, (t_o_sp *)ptr);
		else if (ptr->id == CYLINDER)
			inside_this = inside_cylinder(data, (t_o_cy *)ptr);
		ptr = ptr->next;
	}
	return (inside_this);
}

void	inside_scene(t_data *data, t_object *object)
{
	int		x;
	int		y;
	int		colour;
	t_rgb	rgb;

	rgb = alter_colour(&object->rgb, &data->ambient_lighting->rgb);
	colour = rgb_to_colour(rgb);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			render_loading_bar();
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
}
