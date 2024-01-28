/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:49:40 by helauren          #+#    #+#             */
/*   Updated: 2024/01/25 00:00:17 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

t_object	*parse_sphere(char *s)
{
	t_o_sp	*sp;
	int		i;

	i = 0;
	sp = malloc(sizeof(t_o_sp));
	sp->id = SPHERE;
	i = next_float_index(s, i);
	sp->pos.x = get_double(&s[i]);
	i = next_float_index(s, i);
	sp->pos.y = get_double(&s[i]);
	i = next_float_index(s, i);
	sp->pos.z = get_double(&s[i]);
	i = next_float_index(s, i);
	sp->diameter = get_double(&s[i]);
	i = next_float_index(s, i);
	sp->rgb.r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	sp->rgb.g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	sp->rgb.b = ft_atoi(&s[i]);
	return ((t_object *)sp);
}

t_object	*parse_plane(char *s)
{
	t_o_pl	*pl;
	int		i;

	i = 0;
	pl = malloc(sizeof(t_o_pl));
	pl->id = PLANE;
	i = next_float_index(s, i);
	pl->pos.x = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->pos.y = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->pos.z = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->vector.x = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->vector.y = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->vector.z = get_double(&s[i]);
	i = next_float_index(s, i);
	pl->rgb.r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	pl->rgb.g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	pl->rgb.b = ft_atoi(&s[i]);
	return ((t_object *)pl);
}

void	set_top_bottom(t_o_cy *cy)
{
	t_vec3	normalized_axis;
	t_vec3	up;
	t_vec3	down;

	normalized_axis = normalize(cy->vector);
	up = mul_scalar(normalized_axis, cy->height / 2);
	down = neg(up);
	{
		cy->top_plane = malloc(sizeof(t_o_pl));
		cy->top_plane->rgb = cy->rgb;
		cy->top_plane->pos = vec_add(cy->pos, up);
		cy->top_plane->vector = cy->vector;
	}
	{
		cy->bottom_plane = malloc(sizeof(t_o_pl));
		cy->bottom_plane->rgb = cy->rgb;
		cy->bottom_plane->pos = vec_add(cy->pos, down);
		cy->bottom_plane->vector = cy->vector;
	}
}

void	cylinder_2(t_o_cy *cy,char *s, int i)
{
	i = next_float_index(s, i);
	cy->pos.x = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->pos.y = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->pos.z = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->vector.x = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->vector.y = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->vector.z = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->diameter = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->height = get_double(&s[i]);
	i = next_float_index(s, i);
	cy->rgb.r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	cy->rgb.g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	cy->rgb.b = ft_atoi(&s[i]);
}

t_object	*parse_cylinder(char *s)
{
	t_o_cy	*cy;
	int		i;

	i = 0;
	cy = malloc(sizeof(t_o_cy));
	cy->id = CYLINDER;
	cylinder_2(cy, s, i);
	set_top_bottom(cy);
	normalize(cy->vector);
	return ((t_object *)cy);
}
