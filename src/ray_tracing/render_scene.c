/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/15 17:25:00 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/temp_theo.h"
#include "../../inc/algebra.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// To better understand: the equation of a ray is P = O + t * (V - O)

int	hit_sphere(int x, int y, t_o_sp *sphere, t_data *data)
{
	t_vec3	oc;

	oc = vec_sub(data->first)
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
			my_mlx_pixel_put(&data->img, i, j, BACKGROUND_COLOUR);
			j++;
		}
		i++;
	}
}
