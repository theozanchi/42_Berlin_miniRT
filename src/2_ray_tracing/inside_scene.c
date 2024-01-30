/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:59:51 by helauren          #+#    #+#             */
/*   Updated: 2024/01/30 09:32:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

t_object	*inside_sphere(t_data *data)
{
	t_o_sp	*objects;
	double	distance;

	objects = (t_o_sp *)data->first;
	while (objects)
	{
		if (objects->id == SPHERE)
		{
			distance = calculate_distance(data->camera->pos, objects->pos);
			if (objects->diameter > distance)
				return ((t_object *)objects);
		}
		objects = (t_o_sp *)objects->next;
	}
	return (NULL);
}

t_object	*inside_cylinder(t_data *data)
{
	(void)data;
	return (NULL);
}

t_object	*inside_object(t_data *data)
{
	t_object	*inside_this;

	inside_this = NULL;
	if (data->obj_count == 0)
		return (NULL);
	inside_this = inside_sphere(data);
	if (inside_this == NULL)
		inside_this = inside_cylinder(data);
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
