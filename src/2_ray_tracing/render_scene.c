/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/23 09:53:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

/**
 * @brief Returns the point located at distance t from ray origin
 * 
 * @param ray t_ray
 * @param t double
 * @return t_point3
 */
t_point3	point_on_ray(t_ray *ray, double t)
{
	t_point3	point;

	point.x = ray->origin->x + t * ray->direction->x;
	point.y = ray->origin->y + t * ray->direction->y;
	point.z = ray->origin->z + t * ray->direction->z;
	return (point);
}

/**
 * @brief Computes the colour of a ray based on the object hitted
 * 
 * @param data Main data structure
 * @param ray t_ray
 * @return t_colour (trgb stored under an int)
 */
t_colour	ray_colour(t_data *data, t_ray *ray)
{
	double		t;
	t_object	*hit_obj;
	t_point3	hit_point;
	t_vec3		n;
	t_rgb		rgb;

	t = hit_object(data->first, ray, &hit_obj);
	if (t > 0.0)
	{
		hit_point = point_on_ray(ray, t);
		n = normal_vec3(hit_point, hit_obj, ray, t);
		rgb = compute_colour(hit_obj, data);
		modify_intensity(&rgb, n, hit_point, data);
		return (rgb_to_colour(rgb));
	}
	return (BACKGROUND_COLOUR);
}

/**
 * @brief Allocates memory for a t_ray pointer
 * 
 * @return t_ray* 
 */
t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->direction = malloc(sizeof(t_vec3));
	return (ray);
}

void	create_ray(t_ray *ray, t_data *data, int x, int y);

/**
 * @brief Renders the main scene by processing ray per ray, using the array
 * located at data->vp->points
 * 
 * @param data Main data structure
 */
void	render_scene(t_data *data)
{
	int		x;
	int		y;
	t_ray	*ray;
	int		colour;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	ray = init_ray();
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			render_loading_bar();
			create_ray(ray, data, x, y);
			colour = ray_colour(data, ray);
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
	free_and_set_to_null(2, ray->direction, ray);
}
