/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:22:52 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/13 15:35:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Outputs a pixel to an mlx image
 * 
 * @param img MLX image pointer
 * @param x coordinates of the pixel to output
 * @param y coordinates of the pixel to output
 * @param color format trgb, stored as an int
 */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Computes a colour in format trgb for mlx library
 * 
 * @param rgb custom format
 * @return t_colour (int)
 */
t_colour	rgb_to_colour(t_rgb rgb)
{
	return (*(int *)(unsigned char [4]){rgb.b, rgb.g, rgb.r, 255});
}
