/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:12 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 16:29:46 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_o_c	*parse_camera(char *s)
{
	t_o_c	*camera;
    int     i;

    i = 0;
	camera = malloc(sizeof(t_o_c));
	i = next_float_index(s, i);
	camera->x = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->y = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->z = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->vx = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->vy = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->vz = get_float(&s[i]);
	i = next_float_index(s, i);
	camera->FOV = ft_atoi(&s[i]);
	return (camera);
}

t_o_l	*parse_light(char *s)
{
	t_o_l	*light;
    int     i;

    i = 0;
	light = malloc(sizeof(t_o_c));
	i = next_float_index(s, i);
	light->x = get_float(&s[i]);
	i = next_float_index(s, i);
	light->y = get_float(&s[i]);
	i = next_float_index(s, i);
	light->z = get_float(&s[i]);
	i = next_float_index(s, i);
    light->brightness_ratio = get_float(&s[i]);
	return (light);
}

t_o_a	*parse_ambient_lighting(char *s)
{
	t_o_a	*ambient_lighting;
    int     i;
    
    i = 0;
	ambient_lighting = malloc(sizeof(t_o_a));
	i = next_float_index(s, i);
    ambient_lighting->ratio = get_float(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	ambient_lighting->b = ft_atoi(&s[i]);
	return (ambient_lighting);
}

void	parse_environment(char **red, t_data *data)
{
	int	i;

	i = 0;
	while(red[i])
	{
		if(red[i][0] == 'A')
			data->ambient_lighting = parse_ambient_lighting(red[i]);
		if(red[i][0] == 'C')
			data->camera = parse_camera(red[i]);
		if(red[i][0] == 'L')
			data->light = parse_light(red[i]);
		i++;
	}
}
