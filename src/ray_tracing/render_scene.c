/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/19 11:27:30 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

int	hit_sphere(t_o_sp *sphere, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub(ray->origin, sphere->pos);
	a = dot_product(ray->direction, ray->direction);
	b = 2.0 * dot_product(oc, ray->direction);
	c = dot_product(oc, oc) - sphere->diameter * sphere->diameter / 4;
	discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
		return (1);
	else
		return (0);
}

void	render_scene(t_data *data)
{
	int	i;
	int	j;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGTH)
		{
			if (hit_sphere((t_o_sp *)data->first, data))
				my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
			else
				my_mlx_pixel_put(&data->img, i, j, BACKGROUND_COLOUR);
			j++;
			usleep(1);
			render_loading_bar();
		}
		i++;
	}
}
