// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/15 19:49:17 by helauren          #+#    #+#             */
// /*   Updated: 2024/01/15 21:37:38 by helauren         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../inc/minirt.h"

// int	next_float_index(char *s, int i)
// {
// 	if (ft_isdigit(s[i]) == 1 || s[i] == '-')
// 		while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
// 			i++;
// 	while (s[i] && ft_isdigit(s[i]) != 1 && s[i] != '-')
// 		i++;
// 	if(s[i] == 0)
// 		return (-1);
// 	return (i);
// }

// int	next_neighbouring_float(char *s, int i)
// {
// 	if((ft_isdigit(s[i]) != 1 && s[i] != '-'))
// 		return (-1);
// 	while (s[i] && s[i] != ',' && ft_isspace(s[i]) != 1)
// 			i++;
// 	if(s[i] == ',')
// 		i++;
// 	if(s[i] == 0)
// 		return (-1);
// 	return (i);
// }

// int	count_floats(char *red)
// {
// 	int	i;
// 	int	count;

// 	i = next_float_index(red, 0);
// 	printf("next float = %d\n", i);
// 	count = 0;
// 	while(i >= 0)
// 	{
// 		i = next_neighbouring_float(red, i);
// 		printf("next i = %d\n", i);
// 		if (i != -1)
// 			count++;
// 	}
// 	return (count);
// }

// int	main(void)
// {
// 	char	s1[] = "  	 51.23,56.32,65	   ";
// 	int i1 = count_floats(s1);
// 	printf("i1 = %d\n", i1);

// 	char	s2[] = "      51.23,56.49949        46.324,324,32  ";
// 	int i2 = count_floats(s2);
// 	printf("i2 = %d\n", i2);
// }
