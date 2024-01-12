/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:31 by helauren          #+#    #+#             */
/*   Updated: 2024/01/12 18:06:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Frees the list of objects
 * 
 * @param data Main data structure
 */
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

/**
 * @brief Frees all resources before exiting
 * 
 * @param data Main data structure
 * @return 0 
 */
int	free_resources_and_quit(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_objects(data);
	// free_triple_double(data->vp->points, (int)WIDTH, (int)HEIGTH);
	free(data->vp);
	free_and_set_to_null(4, data->ambient_lighting, data->camera,
		data->light, data);
	exit(EXIT_SUCCESS);
	return (0);
}
