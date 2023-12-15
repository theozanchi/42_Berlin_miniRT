/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_theo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:20:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/15 13:13:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_THEO_H
# define TEMP_THEO_H

# include "minirt.h"

# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGTH
#  define HEIGTH 720
# endif

# ifndef BACKGROUND_COLOUR
#  define BACKGROUND_COLOUR 0x00FFFFFF
# endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	render_scene(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
