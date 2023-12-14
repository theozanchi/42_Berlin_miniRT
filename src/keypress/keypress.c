/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:52:56 by helauren          #+#    #+#             */
/*   Updated: 2023/12/14 01:53:28 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	handle_keypress(int keycode)
{
	if(keycode == KEY_ESC)
	{
		// free_end();
		exit (0);
	}
	return (0);
}
