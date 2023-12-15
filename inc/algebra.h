/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:05:49 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/14 19:22:19 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

/* Data structure *********************************************************** */

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/* Functions **************************************************************** */

t_vec3	vec_add(t_vec3 A, t_vec3 B);
t_vec3	vec_sub(t_vec3 A, t_vec3 B);
t_vec3	vec_mul(t_vec3 A, t_vec3 B);
float	dot_product(t_vec3 A, t_vec3 B);

#endif
