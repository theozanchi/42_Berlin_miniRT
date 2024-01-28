/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rot_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:32:09 by helauren          #+#    #+#             */
/*   Updated: 2024/01/28 20:34:48 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	is_cam_rot_key(int keycode)
{
	if(keycode == K_A || keycode == K_S
		|| keycode == K_W || keycode == K_D
		|| keycode == K_Q || keycode == K_E)
		return (1);
	return (0);
}
