/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:26 by helauren          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/14 15:22:33 by helauren         ###   ########.fr       */
=======
/*   Updated: 2023/12/14 15:35:25 by tzanchi          ###   ########.fr       */
>>>>>>> b13c88dd301fc27b5509750e38624d79e3b79897
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, "AMAZING WINDOW !");
	return (data);
}

int	main(int ac, char **av)
{
	int	fd;
	t_data	*data;

	fd = get_file_fd(av[1]);
	if(ac != 2 || fd < 0)
		return (wrong_arg(fd));
	data = init_data();
	if(parse_scene(data, fd))
	{
		printf("Could not parse, check the content of the .rt file\n");
		return (0);
	}
	mlx_key_hook(data->win_ptr, &press_esc, NULL);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
}
