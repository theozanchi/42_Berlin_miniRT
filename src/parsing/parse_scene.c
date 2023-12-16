/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:24 by helauren          #+#    #+#             */
/*   Updated: 2023/12/16 20:04:41 by helauren         ###   ########.fr       */
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
		s = ft_strjoin_h(s, buff);
		if(br == 0)
			break ;
	}
	free(buff);
	ret = ft_split(s, '\n');
	free(s);
	return (ret);
}

int	next_float_index(char *s, int i)
{
	if(ft_isdigit(s[i]) == 1 || s[i] == '-')
		while(s[i] && s[i] != ',' && s[i] != ' ')
			i++;
	while(s[i] && ft_isdigit(s[i]) != 1 && s[i] != '-')
		i++;
	return (i);
}

double	get_double(char *s)
{
	double	ret;
	int		i;
	double	div;
	double	a;
	int		sign;

	sign = 0;
	i = 0;
	if(s[i] == '-')
	{
		sign = -1;
		i++;
	}
	ret = 0;
	div = 10;
	while(ft_isdigit(s[i]))
	{
		ret = ret * 10;
		ret = ret + s[i] - '0';
		i++;
	}
	if(s[i] == '.')
		i++;
	while(s[i] && s[i] != ',' && s[i] != ' ')
	{
		a = s[i] - '0';
		a = a / div;
		ret = ret + a;
		i++;
		div = div * 10;
	}
	if(sign < 0)
		ret = -ret;
	return (ret);
}

int	parse_scene(t_data *data, int fd)
{
	char	**red;

	red = read_file(fd);
	close(fd);
	parse_environment(red, data);
	data->first = parse_objects(red);
	free_double_str(red);
	return (0);
}
