/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:10:33 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/16 20:10:54 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
// #include "../../inc/temp_theo.h"

// int	keypress_theo(int keycode, t_data *data)
// {
// 	if (keycode == KEY_ESC)
// 		free_resources_and_quit(data);
// 	return (0);
// }

void	init_theo(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "miniRT");
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGTH);
	{
		data->camera = malloc(sizeof(t_o_c));
		data->camera->position.x = 0;
		data->camera->position.y = 0;
		data->camera->position.z = 0;
		data->camera->orientation.x = 0;
		data->camera->orientation.y = 0;
		data->camera->orientation.z = 1;
		data->camera->FOV = 70;
	}
	{
		data->ambient_lighting = malloc(sizeof(t_o_a));
		data->ambient_lighting->ratio = 0.2;
		data->ambient_lighting->r = 255;
		data->ambient_lighting->g = 255;
		data->ambient_lighting->b = 255;
	}
	{
		data->light = malloc(sizeof(t_o_l));
		data->light->x = -40;
		data->light->y = 50;
		data->light->z = 0;
		data->light->brightness_ratio = 0.6;
	}
	{
		data->first = malloc(sizeof(t_o_sp));
		data->first->id = SPHERE;
		{
			t_o_sp	*sphere_data = (t_o_sp *)data->first;
			sphere_data->position.x = 0;
			sphere_data->position.y = 0;
			sphere_data->position.z = 100;
			sphere_data->diameter = 0.5;
			sphere_data->r = 10;
			sphere_data->g = 0;
			sphere_data->b = 255;
		}
		data->first->next = NULL;
	}
}
// void	init_theo(t_data *data)
// {
// 	data->mlx_ptr = mlx_init();
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "miniRT");
// 	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGTH);
// 	{
// 		data->camera = malloc(sizeof(t_o_c));
// 		data->camera->x = 0;
// 		data->camera->y = 0;
// 		data->camera->z = 0;
// 		data->camera->vx = 0;
// 		data->camera->vy = 0;
// 		data->camera->vz = 1;
// 		data->camera->FOV = 70;
// 	}
// 	{
// 		data->ambient_lighting = malloc(sizeof(t_o_a));
// 		data->ambient_lighting->ratio = 0.2;
// 		data->ambient_lighting->r = 255;
// 		data->ambient_lighting->g = 255;
// 		data->ambient_lighting->b = 255;
// 	}
// 	{
// 		data->light = malloc(sizeof(t_o_l));
// 		data->light->x = -40;
// 		data->light->y = 50;
// 		data->light->z = 0;
// 		data->light->brightness_ratio = 0.6;
// 	}
// 	{
// 		data->first = malloc(sizeof(t_o_sp));
// 		data->first->id = SPHERE;
// 		{
// 			t_o_sp	*sphere_data = (t_o_sp *)data->first;
// 			sphere_data->x = 0;
// 			sphere_data->y = 0;
// 			sphere_data->z = 20.6;
// 			sphere_data->diameter = 12.6;
// 			sphere_data->r = 10;
// 			sphere_data->g = 0;
// 			sphere_data->b = 255;
// 		}
// 		data->first->next = NULL;
// 	}
// }

// int	main(void)
// {
// 	t_data	data;

// 	init_theo(&data);
// 	render_scene(&data);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);
// 	mlx_hook(data.win_ptr, ON_DESTROY, 0, &free_resources_and_quit, &data);
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress_theo, &data);
// 	mlx_loop(data.mlx_ptr);
// }
