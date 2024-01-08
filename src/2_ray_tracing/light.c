/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:24:49 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/08 15:49:02 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

double	get_angle_with_light(t_vec3 n, t_point3 hitted_point, t_data *data)
{
	t_vec3	ray;

	ray = vec_normalize(vec_sub(data->light->pos, hitted_point));
	return (acos(dot_product(n, ray)));
}
