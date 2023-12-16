/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/16 20:11:28 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../inc/minirt.h"
// #include "../../inc/temp_theo.h"
// #include "../../inc/algebra.h"

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// // To better understand: the equation of a ray is P = O + t * (V - O)


// int hit_sphere(t_o_sp *sphere, t_data *data)
// {
// 	t_vec3 oc;
	
// 	oc = vec_sub(data->camera->position, sphere->position);
// 	float a = dot_product(data->camera->orientation, data->camera->orientation);
// 	float b = 2.0 * dot_product(oc, data->camera->orientation);
// 	float c = dot_product(oc, oc) - sphere->diameter * sphere->diameter / 4;
// 	float discriminant = b * b - 4 * a * c;
//     if (discriminant >= 0)
//         return (1);
//     else
//         return (0);
// }

// void	render_scene(t_data *data)
// {
// 	int		i;
// 	int		j;

// 	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
// 			&data->img.line_length, &data->img.endian);
// 	i = 0;
// 	j = 0;
// 	while (i < WIDTH)
// 	{
// 		j = 0;
// 		while (j < HEIGTH)
// 		{
// 			if (hit_sphere((t_o_sp *)data->first, data))
// 				my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
// 			else
// 				my_mlx_pixel_put(&data->img, i, j, BACKGROUND_COLOUR);
// 			j++;
// 		}
// 		i++;
// 	}
// }
