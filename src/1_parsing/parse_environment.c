/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:12 by helauren          #+#    #+#             */
/*   Updated: 2024/01/16 21:06:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_amount(char **red)
{
	int	i;
	int	a;
	int	c;
	int	l;

	a = 0;
	c = 0;
	l = 0;
	i = 0;
	while(red[i])
	{
		if (red[i][0] == 'A')
			a++;
		if (red[i][0] == 'C')
			c++;
		if (red[i][0] == 'L' || red[i][0] == 'l')
			l++;
		i++;
	}
	if(a != 1 || c != 1 || l != 1)
		return (1);
	return (0);
}

int	is_valid_char(char *red)
{
	int	i;

	i = 0;
	while(red[i])
	{
		if(ft_isspace(red[i]) != 1 && ft_isdigit(red[i]) != 1 && red[i] != ',' && red[i] != '-' && red[i] != '.')
			return(1);
		i++;
	}
	return (0);
}

int	valid_env(char *red)
{
	int	i;

	i = 1;
	if(ft_isspace(red[i]) != 1 || is_valid_char(&red[i]))
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
	if (ft_strlen(red) < 10)
		return (1);
	if(red[0] != 'A' && red[0] != 'C' && red[0] != 'L' 
		&& (red[0] != 's' && red[1] != 'p') && (red[0] != 'p' && red[1] != 'l'
		&& (red[0] != 'c' && red[1] != 'y')))
		return (1);
	return (0);
}

int	parse_environment(char **red, t_data *data)
{
	int	i;
	int	rm;

	if(check_amount(red))
	{
		printf("You must have one of each, A, C and L, not more, not less\n");
		return (1);
	}
	i = 0;
	while (red[i])
	{
		if(red[i][0] == 'A' || red[i][0] == 'C' || red[i][0] == 'L')
		{
			rm = right_amount(red[i]);
			printf("Env = %c, rm = %d\n", red[i][0], rm);
			if(valid_env(red[i]) || rm)
				return (1);
		}
		if(valid_type(red[i]))
			return (1);
		indiv_acl(data, red, i);
		i++;
	}
	return (0);
}
