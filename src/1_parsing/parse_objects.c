/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:56 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 19:18:00 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "algebra.h"

t_object	*parse_objects_one_by_one(char **red, int i)
{
	t_object	*next;

	next = NULL;
	if (red[i][0] == 's' && red[i][1] == 'p')
		next = parse_sphere(red[i]);
	if (red[i][0] == 'p' && red[i][1] == 'l')
		next = parse_plane(red[i]);
	if (red[i][0] == 'c' && red[i][1] == 'y')
		next = parse_cylinder(red[i]);
	return (next);
}

int	is_object(char **red, int i, t_data *data)
{
	if ((red[i][0] == 's' && red[i][1] == 'p') || (red[i][0] == 'p'
			&& red[i][1] == 'l') || (red[i][0] == 'c' && red[i][1] == 'y'))
	{
		data->obj_count++;
		return (1);
	}
	return (0);
}

void	link_these_objects(t_parse_objects *po, t_data *data)
{
	if (po->first == NULL)
	{
		po->first = po->next;
		po->first->next = NULL;
		po->objects = po->first;
		data->first = po->first;
	}
	else
	{
		po->objects->next = po->next;
		po->objects = po->next;
		po->objects->next = NULL;
	}
}

int	error_check(t_data *data, char **red, int i)
{
	int	ve;

	ve = valid_env(red[i]);
	data->rm_obj = right_amount_obj(red[i]);
	if (ve || data->rm_obj)
	{
		if (ve == 1)
			data->rm_obj = -1;
		free_objects(data);
		return (1);
	}
	return (0);
}

int	parse_objects(char **red, t_data *data)
{
	int				i;
	t_parse_objects	*po;

	i = 0;
	po = malloc(sizeof(t_parse_objects));
	po->first = NULL;
	po->objects = NULL;
	while (red[i])
	{
		if (ft_strlen(red[i]) >= 2)
		{
			if (is_object(red, i, data))
			{
				po->next = parse_objects_one_by_one(red, i);
				link_these_objects(po, data);
				if (error_check(data, red, i))
					return (crappy_norm(po));
			}
		}
		i++;
	}
	free(po);
	return (0);
}
