/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:24 by helauren          #+#    #+#             */
/*   Updated: 2024/01/29 19:37:08 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	**read_file(int fd)
{
	char	*s;
	char	*buff;
	int		br;
	char	**ret;

	s = NULL;
	buff = malloc(sizeof(char) * 101);
	br = 0;
	while (1)
	{
		br = read(fd, buff, 100);
		buff[br] = 0;
		s = ft_strjoin_h(s, buff);
		if (br == 0)
			break ;
	}
	free(buff);
	ret = ft_split(s, '\n');
	free(s);
	return (ret);
}

int	next_float_index(char *s, int i)
{
	if (ft_isdigit(s[i]) == 1 || s[i] == '-')
		while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
			i++;
	while (s[i] && ft_isdigit(s[i]) != 1 && s[i] != '-')
		i++;
	if (s[i] == 0)
		return (-1);
	return (i);
}

int	parse_scene(t_data *data, int fd)
{
	char	**red;
	int		pe;

	red = read_file(fd);
	close(fd);
	pe = parse_environment(red, data);
	data->rm_obj = parse_objects(red, data);
	if (pe || data->rm_obj)
	{
		free_double_str(red);
		return (pe);
	}
	free_double_str(red);
	return (0);
}
