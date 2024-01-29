/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:23:25 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 01:14:22 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	translate_object(t_object *obj)
{
	if (obj->id == SPHERE)
		translate_sphere((t_o_sp *)obj);
	if (obj->id == PLANE)
		translate_plane((t_o_pl *)obj);
	if (obj->id == CYLINDER)
		translate_cylinder((t_o_cy *)obj);
}

int	translation(int keycode, t_data *data)
{
	t_object	*scroll;

	if (keycode == K_V)
		translate_camera(data->camera);
	else if (keycode == K_S)
		translate_ambient(data->ambient_lighting);
	else if (keycode == K_K)
		translate_light(data->light);
	else
	{
		scroll = data->first;
		while (scroll != NULL)
		{
			if (keycode == scroll->personal_id)
				translate_object(scroll);
			scroll = scroll->next;
		}
	}
	return (0);
}
