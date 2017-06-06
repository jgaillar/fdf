/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorcontrols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:42:20 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/25 13:42:26 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		green(int keycode, t_stuff *stuff)
{
	if (keycode == 88)
		stuff->img.color += 0x000011;
	if (keycode == 85)
		stuff->img.color -= 0x000011;
	return (0);
}

int		blue(int keycode, t_stuff *stuff)
{
	if (keycode == 87)
		stuff->img.color += 0x001100;
	if (keycode == 84)
		stuff->img.color -= 0x001100;
	return (0);
}

int		red(int keycode, t_stuff *stuff)
{
	if (keycode == 86)
		stuff->img.color += 0x110000;
	if (keycode == 83)
		stuff->img.color -= 0x110000;
	return (0);
}
