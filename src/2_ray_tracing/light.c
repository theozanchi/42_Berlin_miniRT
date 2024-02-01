/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/01 15:58:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

t_rgb	alter_colour(t_rgb *ref, t_rgb *source)
{
	t_rgb	new;
	int		temp_r;
	int		temp_g;
	int		temp_b;

	temp_r = ref->r * source->r / 255;
	temp_g = ref->g * source->g / 255;
	temp_b = ref->b * source->b / 255;
	if (temp_r <= 255)
		new.r = temp_r;
	else
		new.r = 255;
	if (temp_g <= 255)
		new.g = temp_g;
	else
		new.g = 255;
	if (temp_b <= 255)
		new.b = temp_b;
	else
		new.b = 255;
	return (new);
}

t_ray	*create_shadow_ray(t_hp_data hp_data, t_data *data)
{
	t_ray		*shadow_ray;
	t_point3	origin;
	t_vec3		direction;

	shadow_ray = malloc(sizeof(t_ray));
	shadow_ray->origin = malloc(sizeof(t_vec3));
	shadow_ray->direction = malloc(sizeof(t_vec3));
	origin = vec_add(hp_data.hit_point, mul_scalar(hp_data.n, EPSILON));
	*shadow_ray->origin = origin;
	direction = normalize(vec_sub(data->light->pos, hp_data.hit_point));
	*shadow_ray->direction = direction;
	return (shadow_ray);
}

double	spotlight_intensity(t_hp_data hp_data, t_ray *shadow_ray, t_data *data)
{
	double		intensity;
	double		t;

	t = hit_object(data->first, shadow_ray, NULL);
	if (SHADOW
		&& t > 0.0 && t < vec_len(vec_sub(data->light->pos, hp_data.hit_point)) - EPSILON)
		intensity = 0.0;
	else
		intensity = dot(hp_data.n, *shadow_ray->direction);
	if (intensity < 0.0)
		return (0.0);
	return (intensity);
}

double	specular_intensity(t_hp_data hp_data, t_ray *shadow_ray)
{
	t_vec3	r;
	double	intensity;

	r = vec_sub(mul_scalar(hp_data.n, 2 * 
				dot(hp_data.n, *shadow_ray->direction)),
			*shadow_ray->direction);
	r = normalize(r);
	intensity = pow(dot(r, normalize(*hp_data.ray->direction)), 500);
	if (intensity < 0.0)
		return (0.0);
	return (intensity);
}

void	modify_intensity(t_rgb *rgb, t_hp_data hp_data, t_data *data)
{
	t_ray	*shdw_ray;
	double	spotlight;
	double	specular;
	double	final;

	shdw_ray = create_shadow_ray(hp_data, data);
	spotlight = spotlight_intensity(hp_data, shdw_ray, data);
	specular = 0.0;
	// if (spotlight)
	// {
	// 	// *rgb = alter_colour(rgb, &data->light->rgb);
	// 	if (SPECULAR)
	// 		specular = specular_intensity(hp_data, shdw_ray);
	// }
	final = (spotlight + specular) * data->light->brightness_ratio
		+ data->ambient_lighting->ratio;
	if (final > 1.0)
		final = 1.0;
	rgb->r *= final;
	rgb->g *= final;
	rgb->b *= final;
	free_and_set_to_null(3, shdw_ray->origin, shdw_ray->direction, shdw_ray);
}
