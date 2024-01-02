/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/02 14:53:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

int	exists(t_point3 hit_point)
{
	if (hit_point.x != -1.0 || hit_point.y != -1.0 || hit_point.z != -1.0)
		return (1);
	else
		return (0);
}

t_colour	ray_colour(t_data *data, int x, int y)
{
	t_point3	hit_point;
	t_object	*hitted;
	t_vec3		n;

	hit_point = hit_object(data, x, y, &hitted);
	if (exists(hit_point))
	{
		n = normal_vec3(hit_point, hitted);
		return (0.5 * trgb(255, n.x + 1, n.y + 1, n.z + 1));
	}
	return (BACKGROUND_COLOUR);
}

void	render_scene(t_data *data)
{
	int	x;
	int	y;
	int	colour;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			render_loading_bar();
			colour = ray_colour(data, x, y);
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
}
