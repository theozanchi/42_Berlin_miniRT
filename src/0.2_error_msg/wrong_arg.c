/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:34 by helauren          #+#    #+#             */
/*   Updated: 2024/01/13 15:36:21 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	wrong_arg(int fd)
{
	printf("Invalid Input !!!!!!!!\n");
	if (fd == -1)
		printf("Could not read from given file\n");
	else
	{
		printf("Pass only one argument, a type \"rt\" file from scenes folder\n");
		printf("EX: ./miniRT scenes/first_scene.rt\n");
	}
	return (0);
}
