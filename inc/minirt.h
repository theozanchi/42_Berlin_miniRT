/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:54 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/15 17:28:48 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEY_ESC 65307

enum {
	SPHERE,
	CYLINDER,
	PLANE
};

typedef struct s_o_a // ambient lighting
{
	float	ratio;
	int		r;
	int		g;
	int		b;
}	t_o_a;

typedef struct s_o_c // camera
{
	float	x;
	float	y;
	float	z;
	float	vx;
	float	vy;
	float	vz;
	int		FOV;
}	t_o_c;

typedef struct s_o_l // light
{
	float	x;
	float	y;
	float	z;
	float	brightness_ratio;
}	t_o_l;

typedef struct s_o_sp // sphere
{
	int	id;
	float	x;
	float	y;
	float	z;
	float	diameter;
	int		r;
	int		g;
	int		b;
}	t_o_sp;

typedef struct s_o_pl // plane
{
	int	id;
	float	x;
	float	y;
	float	z;
	float	vx;
	float	vy;
	float	vz;
	int		r;
	int		g;
	int		b;
	struct s_object	*next;
}	t_o_pl;

typedef struct s_o_cy // cylinder
{
	int	id;
	float	x;
	float	y;
	float	z;
	float	vx;
	float	vy;
	float	vz;
	float	diameter;
	float	height;
	int		r;
	int		g;
	int		b;
	struct t_object	*next;
}	t_o_cy;

typedef struct s_object // can be type casted to any object using id
{
	int	id;
	struct s_object	*next;
}				t_object;

typedef struct s_window
{
	unsigned int	height;
	unsigned int	width;
}	t_window;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	window;
	t_object	*first;
	t_o_a		*ambient_lighting;
	t_o_c		*camera;
	t_o_l		*light;
	t_img		img;
}	t_data;

/* free.c ******************************************************************* */

int		free_resources_and_quit(t_data *data);
void	free_objects(t_data *data);

// debugging
void	output_parse(t_data *data);

// closing freeing

// error message
int		wrong_arg(int fd);

// parsing
int			get_file_fd(char *s);
char		**read_file(int fd);
float		get_float(char *s);
int			next_float_index(char *s, int i);
void		parse_environment(char **red, t_data *data);
t_object	*parse_objects(char **red);
int			parse_scene(t_data *data, int fd);

//keypress
int			handle_keypress(int keycode);

#endif