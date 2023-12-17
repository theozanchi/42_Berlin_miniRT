/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:01:36 by helauren          #+#    #+#             */
/*   Updated: 2023/12/17 01:44:03 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	launch_ray(t_ray *rays, t_data *data)
{
	int	i;

	i = 0;
	// reverse_ray() draw_element();
}

void	ray_after_ray(t_ray *rays, t_data *data)
{
	int	x;
	int	y;
	double	angle_yn;

	x = 0;
	while(x < data->window->width)
	{
		y = 0;
		rays->angle = rays->angle_n * (double)x;
		angle_yn = rays->angle_n;
		while(y < data->window->height)
		{
			angle_yn = rays->angle_n * (double)y;
			launch_ray();
			y++;
		}
		x++;
	}
}
