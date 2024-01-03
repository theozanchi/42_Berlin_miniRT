/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 16:44:03 by tzanchi          ###   ########.fr       */
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

t_colour	ray_colour(t_data *data, t_ray *ray)
{
	t_point3	hit_point;
	t_object	*hitted;
	t_vec3		n;

	hit_point = hit_object(data, ray, &hitted);
	if (exists(hit_point))
	{
		n = normal_vec3(hit_point, hitted);
		return (0.5 * trgb(255, n.x + 1, n.y + 1, n.z + 1));
	}
	return (BACKGROUND_COLOUR);
}

void	get_ray(t_ray *ray, t_data *data, int x, int y)
{
	{
		ray->origin->x = data->vp->points[x][y][0];
		ray->origin->y = data->vp->points[x][y][1];
		ray->origin->z = data->vp->points[x][y][2];
	}
	{
		ray->direction->x = data->vp->points[x][y][3];
		ray->direction->y = data->vp->points[x][y][4];
		ray->direction->z = data->vp->points[x][y][5];
	}
}

void	render_scene(t_data *data)
{
	int		x;
	int		y;
	t_ray	*ray;
	int		colour;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	ray = malloc(sizeof(t_ray));
	ray->origin = malloc(sizeof(t_vec3));
	ray->direction = malloc(sizeof(t_vec3));
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			render_loading_bar();
			get_ray(ray, data, x, y);
			colour = ray_colour(data, ray);
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
	free_and_set_to_null(3, ray->direction, ray->origin, ray);
}
