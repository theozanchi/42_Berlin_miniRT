/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:22:10 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/02 10:23:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_double_str(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s && s[i])
	{
		if (s[i] != NULL)
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	if (s != NULL)
		free(s);
	s = NULL;
}

void	free_triple_double(double ***points, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	while (xx < x)
	{
		yy = 0;
		while (yy < y)
		{
			free(points[xx][yy]);
			yy++;
		}
		free(points[xx]);
		xx++;
	}
	free(points);
}
