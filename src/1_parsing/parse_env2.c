/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:29:22 by helauren          #+#    #+#             */
/*   Updated: 2024/01/28 23:50:11 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_o_c	*null_cam_vectors_safety(t_o_c *cam)
{
	if(cam->vector.x == 0 && cam->vector.y == 0 && cam->vector.z == 0)
		cam->vector.z = 1;
	return (cam);
}

t_o_c	*parse_camera(char *s)
{
	t_o_c	*camera;
	int		i;

	i = 0;
	camera = malloc(sizeof(t_o_c));
	i = next_float_index(s, i);
	camera->pos.x = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->pos.y = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->pos.z = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->vector.x = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->vector.y = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->vector.z = get_double(&s[i]);
	i = next_float_index(s, i);
	camera->fov = ft_atoi(&s[i]);
	camera = null_cam_vectors_safety(camera);
	return (camera);
}

t_o_l	*parse_light(char *s)
{
	t_o_l	*light;
	int		i;

	i = 0;
	light = malloc(sizeof(t_o_c));
	i = next_float_index(s, i);
	light->pos.x = get_double(&s[i]);
	i = next_float_index(s, i);
	light->pos.y = get_double(&s[i]);
	i = next_float_index(s, i);
	light->pos.z = get_double(&s[i]);
	i = next_float_index(s, i);
	light->brightness_ratio = get_double(&s[i]);
	i = next_float_index(s, i);
	light->rgb.r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	light->rgb.g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	light->rgb.b = ft_atoi(&s[i]);
	return (light);
}

t_o_a	*parse_ambient_lighting(char *s)
{
	t_o_a	*ambient_lighting;
	int		i;

	i = 0;
	ambient_lighting = malloc(sizeof(t_o_a));
	i = next_float_index(s, i);
	ambient_lighting->ratio = get_double(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->rgb.r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->rgb.g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->rgb.b = ft_atoi(&s[i]);
	return (ambient_lighting);
}
