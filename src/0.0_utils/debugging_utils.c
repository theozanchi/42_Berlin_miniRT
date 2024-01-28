/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:23:46 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/25 02:22:48 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Renders a loading bar for 0 to 100%. Needs to be called before
 * computing any pixel of the viewport
 * 
 */
void	render_loading_bar(void)
{
	static int			pix_ct = 0;
	static int			bar_ct = 0;
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
