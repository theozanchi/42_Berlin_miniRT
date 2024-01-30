/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blind_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:59:51 by helauren          #+#    #+#             */
/*   Updated: 2024/01/30 08:22:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

void	blind_scene(t_data *data)
{
	int		x;
	int		y;
	int		colour;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
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
}
