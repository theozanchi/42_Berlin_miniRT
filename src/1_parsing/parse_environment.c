/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:26:12 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 00:03:11 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_amount(char **red)
{
	int	i;
	t_acl	acl;

	acl.a = 0;
	acl.c = 0;
	acl.l = 0;
	i = 0;
	while(red[i])
	{
		if (red[i][0] == 'A')
			acl.a++;
		if (red[i][0] == 'C')
			acl.c++;
		if (red[i][0] == 'L')
			acl.l++;
		if (ft_strlen(red[i]) < 3)
			return (2);
		if (valid_type(red[i]))
			return (unvalid_type(red[i]));
		i++;
	}
	if(acl.a != 1 || acl.c != 1 || acl.l != 1)
		return (1);
	return (0);
}

int	is_valid_char(char *red)
{
	int	i;

	i = 1;
	if(ft_strlen(red) < 5)
		return (1);
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
	if(is_valid_char(&red[i]))
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
	if(red[0] != 'A' && red[0] != 'C' && red[0] != 'L'
		&& (red[0] != 's' && red[1] != 'p') && (red[0] != 'p' && red[1] != 'l'
		&& (red[0] != 'c' && red[1] != 'y')))
		return (-1);
	return (0);
}

int	acl_return(char *red)
{
	if(red[0] == 'A')
		return (1);
	if(red[0] == 'C')
		return (2);
	if(red[0] == 'L')
		return (3);
	return (-1);
}

int	parse_environment(char **red, t_data *data)
{
	int	i;
	int	rm;
	int	ca;

	ca = check_amount(red);
	if(ca)
		return (failed_first_check(ca));
	i = 0;
	while (red[i])
	{
		if(red[i][0] == 'A' || red[i][0] == 'C' || red[i][0] == 'L')
		{
			rm = right_amount_env(red[i]);
			if(valid_env(red[i]) || rm)
				return (acl_return(red[i]));
		}
		indiv_acl(data, red, i);
		i++;
	}
	return (0);
}
