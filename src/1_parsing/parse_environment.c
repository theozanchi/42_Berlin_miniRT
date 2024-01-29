/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:12 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 17:13:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	valid_env(char *red)
{
	int	i;

	i = 1;
	if (is_valid_char(&red[i]))
		return (1);
	return (0);
}

void	indiv_acl(t_data *data, char **red, int i)
{
	if (red[i][0] == 'A')
		data->ambient_lighting = parse_ambient_lighting(red[i]);
	if (red[i][0] == 'C')
		data->camera = parse_camera(red[i]);
	if (red[i][0] == 'L')
		data->light = parse_light(red[i]);
}

int	valid_type(char *red)
{
	if (ft_strlen(red) < 2)
		return (-2);
	if (red[0] != 'A' && red[0] != 'C' && red[0] != 'L' && (red[0] != 's'
			&& red[1] != 'p') && (red[0] != 'p' && red[1] != 'l'
			&& (red[0] != 'c' && red[1] != 'y')))
		return (-1);
	return (0);
}

int	acl_return(char *red)
{
	if (red[0] == 'A')
		return (1);
	if (red[0] == 'C')
		return (2);
	if (red[0] == 'L')
		return (3);
	return (-1);
}

int	parse_environment(char **red, t_data *data)
{
	int	i;
	int	rm;
	int	ca;
	int	ve;

	ca = check_amount(red);
	if (ca)
		return (failed_first_check(ca));
	i = 0;
	while (red[i])
	{
		if (red[i][0] == 'A' || red[i][0] == 'C' || red[i][0] == 'L')
		{
			rm = right_amount_env(red[i]);
			ve = valid_env(red[i]);
			if (ve || rm)
				return (acl_return(red[i]));
		}
		indiv_acl(data, red, i);
		i++;
	}
	return (0);
}
