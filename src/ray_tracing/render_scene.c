// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   render_scene.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/14 16:05:37 by tzanchi           #+#    #+#             */
// /*   Updated: 2023/12/17 00:25:55 by helauren         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/algebra.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// To better understand: the equation of a ray is P = O + t * (V - O)

int hit_sphere(t_o_sp *sphere, t_data *data)
{
	t_vec3 oc;
	
	oc = vec_sub(data->camera->pos, sphere->pos);
	float a = dot_product(data->camera->vector, data->camera->vector);
	float b = 2.0 * dot_product(oc, data->camera->vector);
	float c = dot_product(oc, oc) - sphere->diameter * sphere->diameter / 4;
	float discriminant = b * b - 4 * a * c;
    if (discriminant >= 0)
        return (1);
    else
        return (0);
}

void	render_loading_bar(void)
{
	static size_t		pix_ct = 0;
	static size_t		bar_ct = 0;
	static const int	pix_nb = WIDTH * HEIGTH;
	static const int	pix_per_bar_el = pix_nb / 72;

	if (pix_ct == 0)
	{
		ft_putstr_fd(LOADING_HEADER, 2);
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Loading: ", 2);
	}
	if (pix_ct++ % pix_per_bar_el == 0)
		ft_putchar_fd(LOADING_BAR[bar_ct++], 2);
	if ((bar_ct == 3) && ((pix_ct - 1) % pix_per_bar_el == 0))
		ft_putstr_fd(ORANGE, 2);
	else if ((bar_ct == 18) && ((pix_ct - 1) % pix_per_bar_el == 0))
		ft_putstr_fd(YELLOW, 2);
	else if ((bar_ct == 51) && ((pix_ct - 1) % pix_per_bar_el == 0))
		ft_putstr_fd(GREEN, 2);
	else if (pix_ct == pix_nb)
	{
		ft_putstr_fd("Done\n", 2);
		ft_putstr_fd(NC, 2);
	}
}

void	render_scene(t_data *data)
{
	int		i;
	int		j;

	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGTH)
		{
			if (hit_sphere((t_o_sp *)data->first, data))
				my_mlx_pixel_put(&data->img, i, j, 0x00FF0000);
			else
				my_mlx_pixel_put(&data->img, i, j, BACKGROUND_COLOUR);
			j++;
			render_loading_bar();
		}
		i++;
	}
}
