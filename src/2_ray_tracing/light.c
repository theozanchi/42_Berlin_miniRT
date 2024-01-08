/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/08 19:24:36 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

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

void	add_ambient_light(t_rgb *rgb, t_data *data)
{
	int	temp_r;
	int	temp_g;
	int	temp_b;

	temp_r = rgb->r + data->ambient_lighting->ratio * data->ambient_lighting->rgb.r;
	temp_g = rgb->g + data->ambient_lighting->ratio * data->ambient_lighting->rgb.g;
	temp_b = rgb->b + data->ambient_lighting->ratio * data->ambient_lighting->rgb.b;
	if (temp_r <= 255)
		rgb->r = temp_r;
	else
		rgb->r = 255;
	if (temp_g <= 255)
		rgb->g = temp_r;
	else
		rgb->g = 255;
	if (temp_b <= 255)
		rgb->b = temp_r;
	else
		rgb->b = 255;
}

void	add_light(t_rgb *rgb, double intensity)
{
	rgb->r *= intensity;
	rgb->g *= intensity;
	rgb->b *= intensity;
}

