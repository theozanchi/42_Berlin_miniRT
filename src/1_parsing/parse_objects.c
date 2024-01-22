/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:56 by helauren          #+#    #+#             */
/*   Updated: 2024/01/22 19:46:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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

t_object	*parse_cylinder(char *s)
{
	t_o_cy	*cy;
	int		i;

	i = 0;
	cy = malloc(sizeof(t_o_cy));
	cy->id = CYLINDER;
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
	set_top_bottom(cy);
	normalize(cy->vector);
	return ((t_object *)cy);
}

t_object	*parse_objects(char **red)
{
	int			i;
	t_object	*objects;
	t_object	*next;
	t_object	*first;

	i = 0;
	first = NULL;
	while (red[i])
	{
		if (red[i][0] == 's')
			next = parse_sphere(red[i]);
		if (red[i][0] == 'p')
			next = parse_plane(red[i]);
		if (red[i][0] == 'c')
			next = parse_cylinder(red[i]);
		if (red[i][0] == 's' || red[i][0] == 'p' || red[i][0] == 'c')
		{
			if (first == NULL)
			{
				first = next;
				first->next = NULL;
				objects = first;
			}
			else
			{
				objects->next = next;
				objects = next;
				objects->next = NULL;
			}
		}
		i++;
	}
	return (first);
}

// this is normitted but somehow segfaults it

// void	parse_spc(t_object *first, t_object *next, t_object *objects)
// {
// 	if(first == NULL)
// 	{
// 		first = next;
// 		first->next = NULL;
// 		objects = first;
// 	}
// 	else
// 	{
// 		objects->next = next;
// 		objects = next;
// 		objects->next = NULL;
// 	}
// }

// t_object	*parse_objects(char **red)
// {
// 	int			i;
// 	t_object	*objects;
// 	t_object	*next;
// 	t_object	*first;

// 	i = 0;
// 	objects = NULL;
// 	next = NULL;
// 	first = NULL;
// 	while(red[i])
// 	{
// 		if(red[i][0] == 's')
// 			next = parse_sphere(red[i]);
// 		if(red[i][0] == 'p')
// 			next = parse_plane(red[i]);
// 		if(red[i][0] == 'c')
// 			next = parse_cylinder(red[i]);
// 		if(red[i][0] == 's' || red[i][0] == 'p' || red[i][0] == 'c')
// 			parse_spc(first, next, objects);
// 		i++;
// 	}
// 	return (first);
// }
