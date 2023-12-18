/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:52:56 by helauren          #+#    #+#             */
/*   Updated: 2023/12/18 10:13:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	handle_keypress(int keycode, t_data *data)
{
	if(keycode == KEY_ESC)
		free_resources_and_quit(data);
	return (0);
}
