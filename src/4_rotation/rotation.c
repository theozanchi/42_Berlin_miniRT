/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:22:19 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 00:21:47 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// C = camera
// A = ambient light
// L = Light

void	rotate_object(t_object *obj)
{
	if(obj->id == SPHERE)
		rotate_sphere((t_o_sp*)obj);
	if(obj->id == PLANE)
		rotate_plane((t_o_pl*)obj);
	if(obj->id == CYLINDER)
		rotate_cylinder((t_o_cy*)obj);
}

int	rotation(int keycode, t_data *data)
{
	t_object	*scroll;

	if(keycode == K_C)
		rotate_camera(data->camera);
	else if(keycode == K_A)
		rotate_ambient(data->ambient_lighting);
	else if(keycode == K_L)
		rotate_light(data->light);
	else
	{
		scroll = data->first;
		while(scroll != NULL)
		{
			if(keycode == scroll->personal_id)
				rotate_object(scroll);
			scroll = scroll->next;
		}
	}
	return (0);
}
