/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:26 by helauren          #+#    #+#             */
/*   Updated: 2024/01/16 22:00:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// error testing later
// if camera position is inside and object
// if vector is 0 vector

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "miniRT");
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGTH);
	data->ambient_lighting = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->first = NULL;
	return (data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	fd = get_file_fd(av[1]);
	if (ac != 2 || fd < 0)
		return (wrong_arg(fd));
	data = init_data();
	if (parse_scene(data, fd))
	{
		printf("Could not parse, check the content of the .rt file\n");
		// free_resources_and_quit(data);
		return (EXIT_FAILURE);
	}
	viewport(data);
	// output_viewport(data->vp->points);
	render_scene(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, &free_resources_and_quit, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
