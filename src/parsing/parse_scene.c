/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:24 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 15:56:14 by helauren         ###   ########.fr       */
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
	while(1)
	{
		br = read(fd, buff, 100);
		buff[br] = 0;
		s = ft_strjoin(s, buff);
		if(br == 0)
			break ;
	}
	ret = ft_split(s, '\n');
	free(s);
	return (ret);
}

int	next_float_index(char *s, int i)
{
	if(ft_isdigit(s[i]) == 1)
		while(ft_isdigit(s[i]) != ',')
			i++;
	while(ft_isdigit(s[i]) != 1 && s[i])
		i++;
	return (i);
}

float	get_float(char *s)
{
	float	ret;
	int		i;
	int		div;

	ret = 0;
	i = 0;
	div = 10;
	while(s[i] && s[i] != '.')
	{
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	while(s[i] && s[i] != ',' && s[i] != ' ')
	{
		ret = ret + ((s[i] - '0') / 10);
		i++;
		div = div * 10;
	}
	return (ret);
}

int	parse_scene(t_data *data, int fd)
{
	char	**red;

	red = read_file(fd);
	close(fd);
	data->first = parse_objects(red);
	parse_environment(red, data);
	return (0);
}
