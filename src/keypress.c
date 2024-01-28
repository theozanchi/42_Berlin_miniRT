/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:52:56 by helauren          #+#    #+#             */
/*   Updated: 2024/01/28 23:38:07 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	// else
	// {
	// 	rotation(keycode, data);
	// 	translation(keycode, data);
	// }

/**
 * @brief Registers desired actions for key actions
 * 
 * @param keycode Code associated with the pressed key
 * @param data Main data structure
 * @return int 0
 */
int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		free_resources_and_quit(data, 0, 0);
	return (0);
}
