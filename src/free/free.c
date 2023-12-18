/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:31 by helauren          #+#    #+#             */
/*   Updated: 2023/12/18 11:20:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"


void	free_objects(t_data *data)
{
	t_object	*current;
	t_object	*temp;

	current = data->first;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp)
			free_and_set_to_null(1, temp);
	}
	data->first = NULL;
}

int	free_resources_and_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	free_objects(data);
	free_and_set_to_null(4, data->ambient_lighting, data->camera, data->light, data);
	exit(EXIT_SUCCESS);
	return (0);
}
