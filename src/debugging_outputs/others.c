/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:41 by helauren          #+#    #+#             */
/*   Updated: 2023/12/21 23:26:36 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// void	output_ray_vectors(t_data *data)
// {
// 	unsigned int	i;
// 	unsigned int	y;

// 	i = 0;
// 	while (i < data->window.width)
// 	{
// 		y = 0;
// 		while (y < data->window.height)
// 		{
// 			printf("ray[%d][%d][0] = %f\n", i, y, data->rays[i][y][0]);
// 			printf("ray[%d][%d][1] = %f\n", i, y, data->rays[i][y][1]);
// 			printf("ray[%d][%d][2] = %f\n", i, y, data->rays[i][y][2]);
// 			y++;
// 		}
// 		i++;
// 	}
// }

void	output_viewport(double ***arr, t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	printf("window height = %u\n", data->window.height);
	while(x < data->window.width)
	{
		y = 0;
		while(y < data->window.height)
		{
			if(x == 1079)
			{
				printf("arr[%d][%d][0] / POS X = %f\n", x, y, arr[x][y][0]);
				printf("arr[%d][%d][1] / POS Y = %f\n", x, y, arr[x][y][1]);
				printf("arr[%d][%d][2] / POS Z = %f\n", x, y, arr[x][y][2]);
				printf("arr[%d][%d][3] / VEC X = %f\n", x, y, arr[x][y][3]);
				printf("arr[%d][%d][4] / VEC Y = %f\n", x, y, arr[x][y][4]);
				printf("arr[%d][%d][5] / VEC Z = %f\n", x, y, arr[x][y][5]);
			}
			y++;
		}
		x++;
	}
}
