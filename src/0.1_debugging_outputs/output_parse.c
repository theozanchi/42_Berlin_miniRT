/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:19:45 by helauren          #+#    #+#             */
/*   Updated: 2024/01/25 00:59:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	output_a(t_o_a *ambient)
{
	printf("ratio = %f\n", ambient->ratio);
	printf("red = %d\n", ambient->rgb.r);
	printf("green = %d\n", ambient->rgb.g);
	printf("blue = %d\n", ambient->rgb.b);
}

void	output_c(t_o_c *camera)
{
	printf("x = %f\n", camera->pos.x);
	printf("y = %f\n", camera->pos.y);
	printf("z = %f\n", camera->pos.z);
	printf("vx = %f\n", camera->vector.x);
	printf("vy = %f\n", camera->vector.y);
	printf("vz = %f\n", camera->vector.z);
	printf("FOV = %d\n", camera->fov);
}

void	output_l(t_o_l *light)
{
	printf("x = %f\n", light->pos.x);
	printf("y = %f\n", light->pos.y);
	printf("z = %f\n", light->pos.z);
	printf("brightness_ratio = %f\n", light->brightness_ratio);
}

void	output_sp(t_o_sp *sphere)
{
	printf("\n\nSPHERE\n");
	printf("id = %d\n", sphere->id);
	printf("x = %f\n", sphere->pos.x);
	printf("y = %f\n", sphere->pos.y);
	printf("z = %f\n", sphere->pos.z);
	printf("diameter = %f\n", sphere->diameter);
	printf("r = %d\n", sphere->rgb.r);
	printf("g = %d\n", sphere->rgb.g);
	printf("b = %d\n", sphere->rgb.b);
}

void	output_pl(t_o_pl *plane)
{
	printf("\n\nPLANE\n");
	printf("id = %d\n", plane->id);
	printf("x = %f\n", plane->pos.x);
	printf("y = %f\n", plane->pos.y);
	printf("z = %f\n", plane->pos.z);
	printf("vx = %f\n", plane->vector.x);
	printf("vy = %f\n", plane->vector.y);
	printf("vz = %f\n", plane->vector.z);
	printf("r = %d\n", plane->rgb.r);
	printf("g = %d\n", plane->rgb.g);
	printf("b = %d\n", plane->rgb.b);
}

void	output_cy(t_o_cy *cylinder)
{
	printf("\n\nCYLINDER\n");
	printf("id = %d\n", cylinder->id);
	printf("x = %f\n", cylinder->pos.x);
	printf("y = %f\n", cylinder->pos.y);
	printf("z = %f\n", cylinder->pos.z);
	printf("vx = %f\n", cylinder->vector.x);
	printf("vy = %f\n", cylinder->vector.y);
	printf("vz = %f\n", cylinder->vector.z);
	printf("diameter = %f\n", cylinder->diameter);
	printf("height = %f\n", cylinder->height);
	printf("r = %d\n", cylinder->rgb.r);
	printf("g = %d\n", cylinder->rgb.g);
	printf("b = %d\n", cylinder->rgb.b);
	printf("top plane\n");
	output_pl(cylinder->top_plane);
	printf("bottom plane\n");
	output_pl(cylinder->bottom_plane);
}

void	output_parse(t_data *data)
{
	t_o_a		*ambient;
	t_o_c		*camera;
	t_o_l		*light;
	t_object	*obj;

	ambient = data->ambient_lighting;
	camera = data->camera;
	light = data->light;
	printf("\nAMBIENT LIGHT\n");
	output_a(ambient);
	printf("\n\nCAMERA\n");
	output_c(camera);
	printf("\n\nLIGHT\n");
	output_l(light);
	obj = data->first;
	while (obj != NULL)
	{
		if (obj->id == 0)
			output_sp((t_o_sp *) obj);
		if (obj->id == 1)
			output_cy((t_o_cy *) obj);
		if (obj->id == 2)
			output_pl((t_o_pl *) obj);
		obj = obj->next;
	}
}
