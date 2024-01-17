/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:41 by helauren          #+#    #+#             */
/*   Updated: 2024/01/16 21:55:46 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	output_viewport(double ***arr)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	printf("window height = %u\n", HEIGTH);
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
