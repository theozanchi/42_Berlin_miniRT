/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 17:42:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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

t_ray	*create_shadow_ray(t_vec3 n, t_point3 hit_point, t_data *data)
{
	t_ray		*shadow_ray;
	t_point3	origin;
	t_vec3		direction;

	shadow_ray = malloc(sizeof(t_ray));
	ft_memset(shadow_ray, 0, sizeof(t_ray));
	origin = vec_add(hit_point, mul_scalar(n, EPSILON));
	shadow_ray->origin = &origin;
	direction = normalize(vec_sub(data->light->pos, hit_point));
	shadow_ray->direction = &direction;
	return (shadow_ray);
}

double	spotlight_intensity(t_vec3 n, t_ray *shadow_ray, t_point3 hit_point, t_data *data)
{
	double		intensity;
	double		t;

	t = hit_object(data->first, shadow_ray, NULL);
	if (SHADOW
		&& t > 0.0 && t < vec_len(vec_sub(data->light->pos, hit_point)))
		intensity = 0.0;
	else
		intensity = dot(n, *shadow_ray->direction)
			* data->light->brightness_ratio;
	if (intensity < 0.0)
		return (0.0);
	return (intensity);
}

void	modify_intensity(t_rgb *rgb, t_vec3 n, t_point3 hit_point, t_data *data)
{
	t_ray	*shadow_ray;
	double	spotlight;
	double	final;

	shadow_ray = create_shadow_ray(n, hit_point, data);
	spotlight = spotlight_intensity(n, shadow_ray, hit_point, data);
	if (spotlight)
		*rgb = alter_colour(rgb, &data->light->rgb);
	final = spotlight + data->ambient_lighting->ratio;
	if (final > 1.0)
		final = 1.0;
	rgb->r *= final;
	rgb->g *= final;
	rgb->b *= final;
	free_and_set_to_null(1, shadow_ray);
}
