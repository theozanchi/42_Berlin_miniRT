/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/12 17:26:19 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

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

double	spotlight_intensity(t_vec3 n, t_point3 hitted_point, t_data *data)
{
	t_vec3	ray;
	double	intensity;

	ray = vec_normalize(vec_sub(data->light->pos, hitted_point));
	intensity = dot_product(n, ray);
	if (intensity > 0)
		return (intensity);
	else
		return (0.0);
}

double	get_local_intensity(t_vec3 n, t_point3 hitted_point, t_data *data)
{
	double	intensity;

	intensity = data->ambient_lighting->ratio;
	intensity += spotlight_intensity(n, hitted_point, data);
	if (intensity > 1.0)
		return (1.0);
	else
		return (intensity);
}

void	modify_intensity(t_rgb *rgb, t_vec3 n, t_point3 hitted_point, t_data *data)
{
	double	intensity;

	intensity = get_local_intensity(n, hitted_point, data);
	rgb->r *= intensity;
	rgb->g *= intensity;
	rgb->b *= intensity;
}