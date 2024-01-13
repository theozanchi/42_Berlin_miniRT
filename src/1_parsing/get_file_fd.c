/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:50:34 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/13 15:36:26 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_file_fd(char *s)
{
	int	i;
	int	fd;

	if (s == NULL || ft_strlen(s) == 0)
		return (-2);
	i = ft_strlen(s) -1;
	if (s[i] != 't' || s[i -1] != 'r' || s[i -2] != '.')
		return (-2);
	fd = open(s, O_RDONLY, 0644);
	return (fd);
}
