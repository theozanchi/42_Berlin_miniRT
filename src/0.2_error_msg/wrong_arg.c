/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:34 by helauren          #+#    #+#             */
/*   Updated: 2024/01/22 21:27:19 by helauren         ###   ########.fr       */
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
