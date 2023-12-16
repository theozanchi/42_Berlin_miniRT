/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:31 by helauren          #+#    #+#             */
/*   Updated: 2023/12/16 19:16:11 by helauren         ###   ########.fr       */
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
	free_and_set_to_null(3, data->ambient_lighting, data->camera, data->light);
	exit(EXIT_SUCCESS);
	return (0);
}
