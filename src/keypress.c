/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:52:56 by helauren          #+#    #+#             */
/*   Updated: 2024/01/03 19:59:20 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
		free_resources_and_quit(data);
	return (0);
}
