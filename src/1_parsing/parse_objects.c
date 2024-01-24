/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:56 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 10:57:41 by tzanchi          ###   ########.fr       */
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
	pl->vector = normalize(pl->vector);
	return ((t_object *)pl);
}

void	set_top_bottom(t_o_cy *cy)
{
	t_vec3	half_height;

	half_height = mul_scalar(cy->vector, cy->height / 2);
	{
		cy->top_plane = malloc(sizeof(t_o_pl));
		cy->top_plane->rgb = cy->rgb;
		cy->top_plane->pos = vec_add(cy->pos, half_height);
		cy->top_plane->vector = cy->vector;
	}
	{
		cy->bottom_plane = malloc(sizeof(t_o_pl));
		cy->bottom_plane->rgb = cy->rgb;
		cy->bottom_plane->pos = vec_sub(cy->pos, half_height);
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
	cy->vector = normalize(cy->vector);
	set_top_bottom(cy);
	return ((t_object *)cy);
}

t_object	*parse_objects_one_by_one(char **red, int i)
{
	t_object *next;

	next = NULL;
	if (red[i][0] == 's' && red[i][1] == 'p')
		next = parse_sphere(red[i]);
	if (red[i][0] == 'p' && red[i][1] == 'l')
		next = parse_plane(red[i]);
	if (red[i][0] == 'c' && red[i][1] == 'y')
		next = parse_cylinder(red[i]);
	return (next);
}

t_object	*parse_objects(char **red, t_data *data)
{
	int			i;
	t_object	*objects;
	t_object	*next;
	t_object	*first;
	int			ve;

	i = 0;
	first = NULL;
	while (red[i])
	{
		if (ft_strlen (red[i]) < 3)
		{
			i++;
			continue ;
		}
		next = parse_objects_one_by_one(red, i);
		if ((red[i][0] == 's' && red[i][1] == 'p') || (red[i][0] == 'p' && red[i][1] == 'l')
			|| (red[i][0] == 'c' && red[i][1] == 'y'))
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
			data->rm_obj = right_amount_obj(red[i]);
			ve = valid_env(red[i]);
			if(ve || data->rm_obj)
			{
				free_objects(data);
				return (NULL);
			}
		}
		i++;
	}
	return (first);
}
