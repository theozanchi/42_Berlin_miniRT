/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:22:52 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/03 19:05:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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
 * @brief Computes a colour in format trgb
 * 
 * @param t transparency (0-255)
 * @param r red (0-255)
 * @param g green (0-255)
 * @param b blue (0-255)
 * @return t_colour (int)
 */
t_colour	trgb(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
