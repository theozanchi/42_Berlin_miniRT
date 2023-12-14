/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:52:56 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 15:36:21 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	handle_keypress(int keycode)
{
	if(keycode == KEY_ESC)
	{
		// free_end();
		exit (0);
	}
	return (0);
}
