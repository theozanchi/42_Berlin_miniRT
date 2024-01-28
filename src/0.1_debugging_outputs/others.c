/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:41 by helauren          #+#    #+#             */
/*   Updated: 2024/01/28 17:38:18 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

void	output_local_vectors(double ***points)
{
	t_vec3	top_left;
	t_vec3	bottom_left;
	t_vec3	top_right;
	t_vec3	vec_down;
	t_vec3	vec_right;

	top_left = vec(points[0][0][0], points[0][0][1], points[0][0][2]);
	bottom_left = vec(points[0][HEIGTH -1][0], points[0][HEIGTH -1][1], points[0][HEIGTH -1][2]);
	top_right = vec(points[WIDTH -1][0][0], points[WIDTH -1][0][1], points[WIDTH -1][0][2]);
	vec_down = calculate_vector(top_left, bottom_left);
	vec_right = calculate_vector(top_left, top_right);
	printf("Vec Down\n");
	output_vec3(vec_down);
	printf("\n");
	printf("Vec Right\n");
	output_vec3(vec_right);
	printf("\n");
}

void	output_vec3(t_vec3 vec)
{
	printf("x = %lf\n", vec.x);
	printf("y = %lf\n", vec.y);
	printf("z = %lf\n", vec.z);
}

void	output_viewport(double ***arr)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			if (x == 0 || x == 1079)
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
