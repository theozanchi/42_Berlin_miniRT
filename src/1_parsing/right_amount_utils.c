/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_amount_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:31:07 by helauren          #+#    #+#             */
/*   Updated: 2024/01/16 20:52:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	empty_end(char *red, int i)
{
	while(ft_isdigit(red[i]))
		i++;
	if(red[i] == '.')
	{
		i++;
		while(ft_isdigit(red[i]))
			i++;
	}
	while(red[i])
	{
		if(ft_isspace(red[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	next_neighbouring_float(char *s, int i)
{
	int	dots;

	dots = 0;
	if((ft_isdigit(s[i]) != 1 && s[i] != '-'))
		return (-1);
	if(s[i] == '-')
		i++;
	while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
	{
		if(s[i] == '.')
			dots++;
		if((ft_isdigit(s[i]) != 1 && s[i] != '.') || dots > 1)
			return (-1);
		i++;
	}
	if(s[i] == ',')
		i++;
	if(s[i] == 0 || ft_isspace(s[i]) == 1)
		return (-1);
	return (i);
}

int	count_floats(char *red)
{
	int	i;
	int	count;

	printf("cf start = %s\n", red);
	count = 0;
	i = next_float_index(red, 0);
	printf("i = %d\n", i);
	if(i != -1)
		count = 1;
	while(i >= 0)
	{
		i = next_neighbouring_float(red, i);
		if (i != -1)
			count++;
	}
	return (count);
}

int	next_neighbouring_int(char *s, int i)
{
	if((ft_isdigit(s[i]) != 1 && s[i] != '-'))
		return (-1);
	while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
	{
		if(s[i] == '.')
			return (-1);
		if(ft_isspace(s[i]) == 1)
			return (-1);
		i++;
	}
	if(s[i] == ',')
		i++;
	if(s[i] == 0 || ft_isspace(s[i]) == 1)
		return (-1);
	return (i);
}

int	count_ints(char *red, int i)
{
	int	count;

	count = 0;
	i = next_float_index(red, i);
	if(i == -1)
		return (-1);
	count = 1;
	while (i >= 0)
	{
		i = next_neighbouring_int(red, i);
		if (i != -1)
			count++;
	}
	return (count);
}
