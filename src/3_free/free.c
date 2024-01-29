/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:31 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 01:22:15 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	crappy_norm(t_parse_objects *po)
{
	free(po);
	return (1);
}

/**
 * @brief Frees the list of objects
 *
 * @param data Main data structure
 */
void	free_objects(t_data *data)
{
	t_object	*current;
	t_object	*temp;
	t_o_cy		*ptr;

	current = data->first;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp)
		{
			if (temp->id == CYLINDER)
			{
				ptr = (t_o_cy *)temp;
				free_and_set_to_null(2, ptr->top_plane, ptr->bottom_plane);
			}
			free_and_set_to_null(1, temp);
		}
	}
	data->first = NULL;
}

/**
 * @brief Frees all resources before exiting
 *
 * @param data Main data structure
 * @return 0
 */
int	free_resources_and_quit(t_data *data, int a, int b)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_objects(data);
	if (a == 0 && b == 0)
	{
		free_triple_double(data->vp->points, (int)WIDTH, (int)HEIGTH);
		free(data->vp);
	}
	free_and_set_to_null(4, data->ambient_lighting, data->camera, data->light,
		data);
	exit(EXIT_SUCCESS);
	return (0);
}
