/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blind_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:59:51 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 21:16:21 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

void	blind_scene(t_data *data)
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
			colour = 0;
			my_mlx_pixel_put(&data->img, x, y, colour);
			y++;
		}
		x++;
	}
	free_and_set_to_null(3, ray->origin, ray->direction, ray);
}
