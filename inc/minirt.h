/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:54 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/22 23:33:24 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define KEY_ESC 65307

# ifndef BACKGROUND_COLOUR
#  define BACKGROUND_COLOUR 0x00000000
# endif

# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGTH
#  define HEIGTH 600
# endif

# define LOADING_HEADER \
	"         0%              25%              50%         \
     75%              100%\n"
# define LOADING_BAR \
	"-----------------|----------------|----------------|-----\
--------- 100% "
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[38;5;208m"
# define GREEN "\033[1;32m"
# define NC "\033[0m"
# define BOLD "\033[1m"

typedef int			t_colour;

enum
{
	SPHERE,
	CYLINDER,
	PLANE,
	NONE
};

enum
{
	Vx,
	Vy,
	Vz,
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef t_vec3		t_point3;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct s_o_a // ambient lighting
{
	double ratio;
	t_rgb rgb;
}					t_o_a;

typedef struct s_o_c // camera
{
	t_vec3 pos;
	t_vec3 vector;
	int fov;
}					t_o_c;

typedef struct s_o_l // light
{
	t_vec3 pos;
	double brightness_ratio;
}					t_o_l;

typedef struct s_o_sp // sphere
{
	int id;
	t_rgb rgb;
	struct s_object *next;
	t_vec3 pos;
	double diameter;
}					t_o_sp;

typedef struct s_o_pl // plane
{
	int id;
	t_rgb rgb;
	struct s_object *next;
	t_vec3 pos;
	t_vec3 vector;
}					t_o_pl;

typedef struct s_o_cy // cylinder
{
	int id;
	t_rgb rgb;
	struct s_object *next;
	t_vec3 pos;
	t_vec3 vector;
	double diameter;
	double height;
	t_vec3 vec_hauteur;
	t_vec3 vec_largeur;
	t_point3 top;
	t_point3 bottom;
}					t_o_cy;

typedef struct s_object // can be type casted to any object using id
{
	int id;
	t_rgb rgb;
	struct s_object *next;
}					t_object;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_ray
{
	double			angle_n;
	double			angle;
	double			angle_radient;
	t_vec3			*origin;
	t_vec3			*direction;
}					t_ray;

typedef struct s_trigo
{
	int				angle_a;
	int				angle_b;
	int				angle_c;
	int				rad_a;
	int				rad_b;
	int				rad_c;
	double			cote_ab;
	double			cote_bc;
	double			cote_ca;
}					t_trigo;

typedef struct s_vp
{
	t_trigo			trigo;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			width;
	double			height;
	double			***points;
}					t_vp;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_object		*first;
	t_o_a			*ambient_lighting;
	t_o_c			*camera;
	t_o_l			*light;
	t_img			img;
	t_vp			*vp;
	int				rm_obj;
}					t_data;

/* free.c ******************************************************************* */

int					free_resources_and_quit(t_data *data);
void				free_objects(t_data *data);

// debugging
void				output_parse(t_data *data);
void				render_loading_bar(void);
void				output_ray_vectors(t_data *data);
void				output_viewport(double ***arr);

// error message
int					wrong_arg(int fd);
void	error_parsing(int ps, t_data *data);

// parsing
int					get_file_fd(char *s);
char				**read_file(int fd);
double				get_double(char *s);
int					next_float_index(char *s, int i);
int					parse_environment(char **red, t_data *data);
t_object			*parse_objects(char **red, t_data *data);
int					parse_scene(t_data *data, int fd);
t_o_a				*parse_ambient_lighting(char *s);
t_o_l				*parse_light(char *s);
t_o_c				*parse_camera(char *s);
int					count_ints(char *red, int i);
int					next_neighbouring_int(char *s, int i);
int					count_floats(char *red);
int					next_neighbouring_float(char *s, int i);
int					right_amount_env(char *red);
int					empty_end(char *red, int i);
int					is_between_one(double num);
int					move_up_three(char *red, int i);
t_o_c				*parse_camera(char *s);
t_o_l				*parse_light(char *s);
t_o_a				*parse_ambient_lighting(char *s);
int					right_amount_c(char *red);
int					right_amount_obj(char *red);
int					iterate_three_one_floats(char *red, int i);
int					iterate_rgb_ints(char *red, int i);
int					valid_env(char *red);

// RT
void				viewport(t_data *data);

// keypress
int					handle_keypress(int keycode, t_data *data);

// rendering
void				render_scene(t_data *data);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_colour			rgb_to_colour(t_rgb rgb);

// hit_object.c
int					is_on_line(t_point3 center, t_vec3 vector, double len,
						t_point3 hit_point);
t_point3			point_on_ray(t_ray *ray, double t);
double				hit_object(t_object *hittables, t_ray *ray,
						t_object **hitted);

// normal_vector.c
// t_vec3		cyl_nor_vec3(t_point3 hit_point, t_o_cy *cyl);
t_vec3				normal_vec3(t_point3 hit_point, t_object *hitted,
						t_ray *ray, double t);

// light.c
double				spotlight_intensity(t_vec3 n, t_point3 hitted_point,
						t_data *data);
t_rgb				compute_colour(t_object *hitted_object, t_data *data);
void				modify_intensity(t_rgb *rgb, t_vec3 n,
						t_point3 hitted_point, t_data *data);

#endif