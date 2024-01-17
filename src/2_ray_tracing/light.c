/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/17 14:55:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

t_rgb	compute_colour(t_object *hitted_object, t_data *data)
{
	t_rgb	rgb;
	int		temp_r;
	int		temp_g;
	int		temp_b;

	temp_r = hitted_object->rgb.r * data->ambient_lighting->rgb.r / 255;
	temp_g = hitted_object->rgb.g * data->ambient_lighting->rgb.g / 255;
	temp_b = hitted_object->rgb.b * data->ambient_lighting->rgb.b / 255;
	if (temp_r <= 255)
		rgb.r = temp_r;
	else
		rgb.r = 255;
	if (temp_g <= 255)
		rgb.g = temp_g;
	else
		rgb.g = 255;
	if (temp_b <= 255)
		rgb.b = temp_b;
	else
		rgb.b = 255;
	return (rgb);
}

double	spotlight_intensity(t_vec3 n, t_point3 hit_point, t_data *data)
{
	t_ray		*shadow_ray;
	t_point3	origin;
	t_vec3		direction;
	double		intensity;
	double		t;

	shadow_ray = malloc(sizeof(t_ray));
	ft_memset(shadow_ray, 0, sizeof(t_ray));
	origin = vec_add(hit_point, mul_scalar(n, EPSILON));
	shadow_ray->origin = &origin;
	direction = normalize(vec_sub(data->light->pos, hit_point));
	shadow_ray->direction = &direction;
	t = hit_object(data->first, shadow_ray, NULL);
	if (t > 0.0 && t < vec_len(vec_sub(data->light->pos, hit_point)))
		intensity = 0.0;
	else
		intensity = dot(n, *shadow_ray->direction);
	free_and_set_to_null(1, shadow_ray);
	return (intensity);
}

double	get_local_intensity(t_vec3 n, t_point3 hit_point, t_data *data)
{
	double	intensity;

	intensity = data->ambient_lighting->ratio;
	intensity += spotlight_intensity(n, hit_point, data);
	if (intensity > 1.0)
		return (1.0);
	else
		return (intensity);
}

void	modify_intensity(t_rgb *rgb, t_vec3 n, t_point3 hit_point, t_data *data)
{
	double	intensity;

	intensity = get_local_intensity(n, hit_point, data);
	rgb->r *= intensity;
	rgb->g *= intensity;
	rgb->b *= intensity;
}
