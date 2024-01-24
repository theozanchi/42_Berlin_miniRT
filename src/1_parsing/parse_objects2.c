/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:49:40 by helauren          #+#    #+#             */
/*   Updated: 2024/01/24 11:38:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "algebra.h"

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

int	is_object(char **red, int i)
{
	if ((red[i][0] == 's' && red[i][1] == 'p') || (red[i][0] == 'p' && red[i][1] == 'l')
		|| (red[i][0] == 'c' && red[i][1] == 'y'))
		return (1);
	return (0);
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
		if (ft_strlen (red[i]) >= 2)
		{
			next = parse_objects_one_by_one(red, i);
			if (is_object(red, i))
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
		}
		i++;
	}
	return (first);
}
