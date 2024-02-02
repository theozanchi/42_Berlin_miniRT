/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:26 by helauren          #+#    #+#             */
/*   Updated: 2024/02/02 10:26:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_memset(data, 0, sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGTH, "miniRT");
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGTH);
	data->ambient_lighting = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->first = NULL;
	data->obj_count++;
	data->rm_obj = 0;
	return (data);
}

void	launching_mlx(t_data *data)
{
	t_object	*inside_this;

	viewport(data);
	inside_this = inside_object(data);
	if (data->camera->fov == 0.0)
		blind_scene(data);
	else if (inside_this != NULL)
		inside_scene(data, inside_this);
	else
		render_scene(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, &quit_from_cross, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	int		ps;

	fd = get_file_fd(av[1]);
	if (ac != 2 || fd < 0)
		return (wrong_arg(fd));
	data = init_data();
	ps = parse_scene(data, fd);
	if (ps || data->rm_obj)
	{
		error_parsing(ps, data);
		if (ps >= 0 || ps == -2)
			free_resources_and_quit(data, ps, data->rm_obj);
		return (EXIT_FAILURE);
	}
	launching_mlx(data);
	return (0);
}
