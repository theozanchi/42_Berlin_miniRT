/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:19:45 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 20:00:18 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	output_a(t_o_a *ambient)
{
	printf("ratio = %f\n", ambient->ratio);
	printf("red = %d\n", ambient->r);
	printf("green = %d\n", ambient->g);
	printf("blue = %d\n", ambient->b);
}

void output_c(t_o_c *camera)
{
	printf("x = %f\n", camera->x);
	printf("y = %f\n", camera->y);
	printf("z = %f\n", camera->z);
	printf("vx = %f\n", camera->vx);
	printf("vy = %f\n", camera->vy);
	printf("vz = %f\n", camera->vz);
	printf("FOV = %d\n", camera->FOV);
}

void output_l(t_o_l *light)
{
	printf("x = %f\n", light->x);
	printf("y = %f\n", light->y);
	printf("z = %f\n", light->z);
	printf("brightness_ratio = %f\n", light->brightness_ratio);
}

void output_sp(t_o_sp *sphere)
{
	printf("\n\nSPHERE\n");
	printf("id = %c\n", sphere->id);
	printf("x = %f\n", sphere->x);
	printf("y = %f\n", sphere->y);
	printf("z = %f\n", sphere->z);
	printf("diameter = %f\n", sphere->diameter);
	printf("r = %d\n", sphere->r);
	printf("g = %d\n", sphere->g);
	printf("b = %d\n", sphere->b);
}

void output_pl(t_o_pl *plane)
{
	printf("\n\nPLANE\n");
	printf("id = %c\n", plane->id);
	printf("x = %f\n", plane->x);
	printf("y = %f\n", plane->y);
	printf("z = %f\n", plane->z);
	printf("vx = %f\n", plane->vx);
	printf("vy = %f\n", plane->vy);
	printf("vz = %f\n", plane->vz);
	printf("r = %d\n", plane->r);
	printf("g = %d\n", plane->g);
	printf("b = %d\n", plane->b);
}

void output_cy(t_o_cy *cylinder)
{
	printf("\n\nCYLINDER\n");
	printf("id = %c\n", cylinder->id);
	printf("x = %f\n", cylinder->x);
	printf("y = %f\n", cylinder->y);
	printf("z = %f\n", cylinder->z);
	printf("vx = %f\n", cylinder->vx);
	printf("vy = %f\n", cylinder->vy);
	printf("vz = %f\n", cylinder->vz);
	printf("diameter = %f\n", cylinder->diameter);
	printf("height = %f\n", cylinder->height);
	printf("r = %d\n", cylinder->r);
	printf("g = %d\n", cylinder->g);
	printf("b = %d\n", cylinder->b);
}

void	output_parse(t_data *data)
{
	t_o_a	*ambient = data->ambient_lighting;
	t_o_c	*camera = data->camera;
	t_o_l	*light = data->light;
	t_object	*obj;

	printf("\nAMBIENT LIGHT\n");
	output_a(ambient);
	printf("\n\nCAMERA\n");
	output_c(camera);
	printf("\n\nLIGHT\n");
	output_l(light);
	obj = data->first_object;
	while(obj != NULL)
	{
		if(obj->id == 's')
			output_sp((t_o_sp *) obj);
		if(obj->id == 'p')
			output_pl((t_o_pl *) obj);
		if(obj->id == 'c')
			output_cy((t_o_cy *) obj);
		obj = obj->next;
	}
}
