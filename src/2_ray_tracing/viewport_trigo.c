/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_trigo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:23:18 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 01:24:17 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

double	longueur_hypothenuse(t_data *data)
{
	double	hypothenuse;
	double	rad;
	double	degrees;

	degrees = (double)(data->camera->fov / 2.0);
	rad = degrees * (M_PI / 180.0);
	hypothenuse = 1.0 / cos(rad);
	return (hypothenuse);
}

double	longueur_aigu(double hypothenuse)
{
	double	aigu;

	aigu = sqrt((hypothenuse * hypothenuse) - 1);
	return (aigu);
}

void	viewport_trigo(t_data *data)
{
	data->vp->trigo.angle_a = 90;
	data->vp->trigo.angle_b = data->camera->fov / 2;
	data->vp->trigo.angle_c = 180 - data->vp->trigo.angle_a
		- data->vp->trigo.angle_b;
	data->vp->trigo.rad_a = data->vp->trigo.angle_a * (PI / 180);
	data->vp->trigo.rad_b = data->vp->trigo.angle_b * (PI / 180);
	data->vp->trigo.rad_c = data->vp->trigo.angle_c * (PI / 180);
	data->vp->trigo.cote_ab = 1;
	data->vp->trigo.cote_bc = ((data->vp->trigo.cote_ab
				* sin(data->vp->trigo.rad_a)) / sin(data->vp->trigo.rad_c));
	data->vp->trigo.cote_ca = ((data->vp->trigo.cote_ab
				* sin(data->vp->trigo.rad_b)) / sin(data->vp->trigo.rad_c));
	data->vp->hypothenuse = longueur_hypothenuse(data);
	data->vp->aigu = longueur_aigu(data->vp->hypothenuse);
	data->vp->win_ratio = (((double)HEIGTH / (double)WIDTH) * data->vp->aigu);
}
