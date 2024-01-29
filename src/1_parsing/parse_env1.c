/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:21:12 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 17:57:36 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_amount(char **red)
{
	int		i;
	t_acl	acl;

	acl.a = 0;
	acl.c = 0;
	acl.l = 0;
	i = 0;
	while (red[i])
	{
		if (red[i][0] == 'A' && ft_isspace(red[i][1]) == 1)
			acl.a++;
		if (red[i][0] == 'C' && ft_isspace(red[i][1]) == 1)
			acl.c++;
		if (red[i][0] == 'L' && ft_isspace(red[i][1]) == 1)
			acl.l++;
		if (ft_strlen(red[i]) < 3)
			return (2);
		if (valid_type(red[i]))
			return (unvalid_type(red[i]));
		i++;
	}
	if (acl.a != 1 || acl.c != 1 || acl.l != 1)
		return (1);
	return (0);
}

int	is_valid_char(char *red)
{
	int	i;

	i = 1;
	if (ft_strlen(red) < 5)
		return (1);
	while (red[i])
	{
		if (ft_isspace(red[i]) != 1 && ft_isdigit(red[i]) != 1 && red[i] != ','
			&& red[i] != '-' && red[i] != '.')
			return (1);
		i++;
	}
	return (0);
}
