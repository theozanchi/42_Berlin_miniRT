/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/24 19:48:04 by helauren         ###   ########.fr       */
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
		n = normal_vec3(hit_point, hit_obj, ray);
		rgb = compute_colour(hit_obj, data);
		modify_intensity(&rgb, n, hit_point, data);
		if (DEBUG_COLOR)
			printf("Normal: (%.2f, %.2f, %.2f)\n", n.x, n.y, n.z);
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
	ray->origin = malloc(sizeof(t_vec3));
	ray->direction = malloc(sizeof(t_vec3));
	return (ray);
}

/**
 * @brief Get the ray object located at coordinates [x][y] in data->vp->points
 * 
 * @param ray The ray object to populate
 * @param data Main data structure
 * @param x Abscissa coordinate
 * @param y Ordinate coordinate
 */
void	get_ray(t_ray *ray, t_data *data, int x, int y)
{
	{
		*ray->origin = data->camera->pos;
	}
	{
		ray->direction->x = data->vp->points[x][y][3];
		ray->direction->y = data->vp->points[x][y][4];
		ray->direction->z = data->vp->points[x][y][5];
	}
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
			get_ray(ray, data, x, y);
			// create_ray(ray, data, x, y);
			if (DEBUG_COLOR)
			{
				printf("\nPixel (%i, %i)\n", x, y);
				printf("Ray origin: (%.2f, %.2f, %.2f)\n", ray->origin->x, ray->origin->y, ray->origin->z);
				printf("Ray direction: (%.2f, %.2f, %.2f)\n", ray->direction->x, ray->direction->y, ray->direction->z);
			}
			colour = ray_colour(data, ray);
			if (DEBUG_COLOR)
				printf("Colour: 0x%X\n", colour);;
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
	free_and_set_to_null(3, ray->origin, ray->direction, ray);
}
