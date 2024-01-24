/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:56:47 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 00:22:45 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	translate_sphere(t_o_sp *sphere)
{
	sphere->pos.x = sphere->pos.x - 0.5;
	return (0);
}

int	translate_plane(t_o_pl *plane)
{
	plane->pos.x = plane->pos.x - 0.5;
	return (0);
}

int	translate_cylinder(t_o_cy *cylinder)
{
	cylinder->pos.x = cylinder->pos.x - 0.5;
	return (0);
}
