/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:54 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/29 16:36:15 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keys.h"
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
#  define WIDTH 1024
# endif

# ifndef HEIGTH
# define HEIGTH 768
# endif

# ifndef EPSILON
#  define EPSILON 1e-6
# endif

/* ************************************************************************** */

// These constants can be set to 0 or 1 to activate certain functionalities

# ifndef SHADOW
#  define SHADOW 1
# endif

# ifndef SPECULAR
#  define SPECULAR 1
# endif

# ifndef DEBUG
#  define DEBUG 1
# endif

# ifndef DEBUG_VIEWPORT
#  define DEBUG_VIEWPORT 0
# endif

# ifndef DEBUG_SPOTLIGHT
#  define DEBUG_SPOTLIGHT 0
# endif

# ifndef DEBUG_COLOR
#  define DEBUG_COLOR 0
# endif

# ifndef DEBUG_PARSE
#  define DEBUG_PARSE 0
# endif

/* ************************************************************************** */

# define LOADING_HEADER "         0%              25%              50%         \
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

enum e_hit_part {
	NOT_HIT,
	TUBE,
	TOP,
	BOTTOM
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_acl
{
	int	a;
	int	c;
	int	l;
}				t_acl;

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef t_vec3		t_point3;

typedef struct s_mtx33
{
	t_vec3	c0;
	t_vec3	c1;
	t_vec3	c2;
}	t_mtx33;

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
	t_point3	pos;
	t_vec3		vector;
	int			fov;
}	t_o_c;

typedef struct s_o_l // light
{
	t_point3	pos;
	double		brightness_ratio;
	t_rgb		rgb;
}	t_o_l;

typedef struct s_o_sp // sphere
{
	int				id;
	t_rgb			rgb;
	struct s_object	*next;
	char			personal_id;
	t_point3		pos;
	double			diameter;
}	t_o_sp;

typedef struct s_o_pl // plane
{
	int				id;
	t_rgb			rgb;
	struct s_object	*next;
	char			personal_id;
	t_point3		pos;
	t_vec3			vector;
}	t_o_pl;

typedef struct s_o_cy // cylinder
{
	int				id;
	t_rgb			rgb;
	struct s_object	*next;
	char			personal_id;
	t_point3		pos;
	t_vec3			vector;
	double			diameter;
	double			height;
	t_o_pl			*top_plane;
	t_o_pl			*bottom_plane;
	enum e_hit_part	hit_part;
}	t_o_cy;

typedef struct s_object // can be type casted to any object using id
{
	int				id;
	t_rgb			rgb;
	struct s_object	*next;
	char			personal_id;
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
	double			hypothenuse;
	double			aigu;
	double			win_ratio;
	t_vec3			local_right;
	t_vec3			local_up;
	t_vec3			local_down;
}					t_vp;

typedef struct s_hp_data
{
	t_point3	hit_point;
	t_ray		*ray;
	t_vec3		n;
}	t_hp_data;

typedef struct s_pdp
{
	unsigned int	x;
	unsigned int	y;
	double			distance_y;
	double			distance_x;
}					t_pdp;

typedef struct s_parse_objects
{
	t_object	*objects;
	t_object	*next;
	t_object	*first;
}				t_parse_objects;

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
	int				obj_count;
}					t_data;

// main
void	launching_mlx(t_data *data);

/* free.c ******************************************************************* */

int					free_resources_and_quit(t_data *data, int a, int b);
void				free_objects(t_data *data);
int					crappy_norm(t_parse_objects *po);

// debugging
void				output_parse(t_data *data);
void				render_loading_bar(void);
void				output_ray_vectors(t_data *data);
void				output_viewport(double ***arr);
void				output_vec3(t_vec3 vec);
void				output_local_vectors(double ***points);

// error message
int					wrong_arg(int fd);
void				error_parsing(int ps, t_data *data);
int					failed_first_check(int ca);
int					unvalid_type(char *red);

// parsing
double				get_double(char *s);
int					get_file_fd(char *s);
char				**read_file(int fd);
double				get_double(char *s);
int					next_float_index(char *s, int i);
int					parse_environment(char **red, t_data *data);
int					parse_objects(char **red, t_data *data);
int					parse_scene(t_data *data, int fd);
t_o_a				*parse_ambient_lighting(char *s);
t_o_l				*parse_light(char *s);
t_o_c				*parse_camera(char *s);
void				cylinder_2(t_o_cy *cy,char *s, int i);
void				set_top_bottom(t_o_cy *cy);
t_object			*parse_plane(char *s);
t_object			*parse_sphere(char *s);
t_object			*parse_cylinder(char *s);
int					count_ints(char *red, int i);
int					next_neighbouring_int(char *s, int i);
int					count_floats(char *red);
int					next_neighbouring_float(char *s, int i);
int					right_amount_env(char *red);
int					empty_end(char *red, int i);
int					is_between_one(double num);
int					move_up_three(char *red, int i);
int					right_amount_c(char *red);
int					right_amount_obj(char *red);
int					iterate_three_one_floats(char *red, int i);
int					iterate_rgb_ints(char *red, int i);
int					iterate_three_floats(char *red, int i);
int					valid_env(char *red);
int					valid_type(char *red);
int					is_valid_char(char *red);
int					check_amount(char **red);

// Viewport
void				viewport(t_data *data);
t_vec3				viewport_center(t_data *data, t_vec3 start_pos);
void				viewport_local_vectors_and_height(t_data *data);
void				viewport_trigo(t_data *data);


// keypress
int					handle_keypress(int keycode, t_data *data);

// rendering
void				render_scene(t_data *data);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_colour			rgb_to_colour(t_rgb rgb);

// rotation
int	rotation(int keycode, t_data *data);
int	rotate_sphere(t_o_sp *sphere);
int	rotate_plane(t_o_pl *plane);
int	rotate_cylinder(t_o_cy *cylinder);
int	rotate_camera(t_o_c *camera);
int	rotate_ambient(t_o_a *ambient);
int	rotate_light(t_o_l *light);
int	is_cam_rot_key(int keycode);

// translation
int	translation(int keycode, t_data *data);
int	translate_sphere(t_o_sp *sphere);
int	translate_plane(t_o_pl *plane);
int	translate_cylinder(t_o_cy *cylinder);
int	translate_camera(t_o_c *camera);
int	translate_ambient(t_o_a *ambient);
int	translate_light(t_o_l *light);

//hit_object.c
double				hit_plane(t_o_pl *plane, t_ray *ray, t_object ***hit_obj);
double				hit_cylinder(t_o_cy *cyl, t_ray *ray, t_object ***hit_obj);
t_point3			point_on_ray(t_ray *ray, double t);
double				hit_object(t_object *hittables, t_ray *ray, t_object **hit_obj);

//normal_vector.c
t_vec3				normal_vec3(t_point3 hit_point, t_object *hit_obj, t_ray *ray);

// light.c
t_rgb				alter_colour(t_rgb *ref, t_rgb *source);
void				modify_intensity(t_rgb *rgb, t_hp_data hp_data, t_data *data);
double				spotlight_intensity(t_hp_data hp_data, t_ray *shadow_ray, t_data *data);
t_rgb				compute_colour(t_object *hitted_object, t_data *data);

#endif