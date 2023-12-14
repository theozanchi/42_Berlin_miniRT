/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:56 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 02:07:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_object	*parse_sphere(char *s)
{
	t_o_sp	*sp;
	int		i;

    i = 0;
	sp = malloc(sizeof(t_o_sp));
	sp->id = 's';
	i = next_float_index(s, i);
	sp->x = get_float(&s[i]);
	i = next_float_index(s, i);
	sp->y = get_float(&s[i]);
	i = next_float_index(s, i);
	sp->z = get_float(&s[i]);
	i = next_float_index(s, i);
	sp->diameter = get_float(&s[i]);
	i = next_float_index(s, i);
	sp->r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	sp->g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	sp->b = ft_atoi(&s[i]);
	return ((t_object *)sp);
}

t_object	*parse_plane(char *s)
{
	t_o_pl	*pl;
	int		i;

    i = 0;
	pl = malloc(sizeof(t_o_pl));
	pl->id = 'p';
	i = next_float_index(s, i);
	pl->x = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->y = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->z = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->vx = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->vy = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->vz = get_float(&s[i]);
	i = next_float_index(s, i);
	pl->r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	pl->g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	pl->b = ft_atoi(&s[i]);
	return ((t_object *)pl);
}

t_object	*parse_cylinder(char *s)
{
	t_o_cy	*cy;
	int		i;

    i = 0;
	cy = malloc(sizeof(t_o_cy));
	cy->id = 'c';
	i = next_float_index(s, i);
	cy->x = get_float(&s[i]);
	i = next_float_index(s, i);
	cy->y = get_float(&s[i]);
	i = next_float_index(s, i);
	cy->z = get_float(&s[i]);
	i = next_float_index(s, i);
	cy->diameter = get_float(&s[i]);
	i = next_float_index(s, i);
	cy->height = get_float(&s[i]);
	i = next_float_index(s, i);
	cy->r = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	cy->g = ft_atoi(&s[i]);
	i = next_float_index(s, i);
	cy->b = ft_atoi(&s[i]);
	return ((t_object *)cy);
}

t_object	*parse_objects(char **red)
{
	int			i;
	t_object	*objects;
	t_object	*first;

	i = 0;
	objects = malloc(sizeof(t_object));
	first = objects;
	while(red[i])
	{
		if(red[i][0] == 's')
			objects = parse_sphere(red[i]);
		if(red[i][0] == 'p')
			objects = parse_plane(red[i]);
		if(red[i][0] == 'c')
			objects = parse_cylinder(red[i]);
		i++;
	}
    return (first);
}