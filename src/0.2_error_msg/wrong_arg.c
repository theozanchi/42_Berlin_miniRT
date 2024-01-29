/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:34 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 18:52:24 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	error_parsing(int ps, t_data *data)
{
	if (ps == -2)
		return ;
	if (data->rm_obj < 0 || ps < 0 || data->rm_obj == 1)
	{
		printf("Invalid content has been detected in file\n");
		return ;
	}
	printf("Parsing error with ");
	if (ps == 1)
		printf("Ambient light ");
	if (ps == 2)
		printf("Camera ");
	if (ps == 3)
		printf("Light ");
	if (data->rm_obj == 4)
		printf("Sphere ");
	if (data->rm_obj == 5)
		printf("Plane ");
	if (data->rm_obj == 6)
		printf("Cylinder ");
	printf("\n");
}

int	failed_first_check(int ca)
{
	if (ca == 1)
		printf("You must have one of each, A, C and L, not more, not less\n");
	else if (ca == 2)
		printf("One of the lines is way to short come on make an effort !\n");
	if (ca == 3)
		return (-2);
	return (-2);
}

int	unvalid_type(char *red)
{
	printf("This line is not recognized as valid \"%s\"\n", red);
	return (3);
}

int	wrong_arg(int fd)
{
	printf("Invalid Input !!!!!!!!\n");
	if (fd == -1)
		printf("Could not read from given file\n");
	else
	{
		printf("Pass only one argument, \
			a type \"rt\" file from scenes folder\n");
		printf("EX: ./miniRT scenes/first_scene.rt\n");
	}
	return (0);
}
