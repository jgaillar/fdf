/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:59:52 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/25 13:59:53 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		deplahor(int keycode, t_stuff *stuff)
{
	if (keycode == 124)
	{
		stuff->fdf.gpadding = (stuff->fdf.gpadding + 2);
	}
	if (keycode == 123)
	{
		stuff->fdf.gpadding = (stuff->fdf.gpadding - 1);
	}
	return (0);
}

int		deplaver(int keycode, t_stuff *stuff)
{
	if (keycode == 126)
	{
		stuff->fdf.hpadding = (stuff->fdf.hpadding - 1);
	}
	if (keycode == 125)
	{
		stuff->fdf.hpadding = (stuff->fdf.hpadding + 1);
	}
	return (0);
}

int		zoom(int keycode, t_stuff *stuff)
{
	if (keycode == 24)
	{
		stuff->fdf.padding = (stuff->fdf.padding + 0.5);
	}
	if (keycode == 27)
	{
		if (stuff->fdf.padding > 0)
		{
			stuff->fdf.padding = (stuff->fdf.padding - 0.5);
		}
	}
	return (0);
}

int		level(int keycode, t_stuff *stuff)
{
	if (keycode == 78)
	{
		stuff->fdf.k = (stuff->fdf.k - 0.001 * stuff->fdf.maxy);
	}
	if (keycode == 69)
	{
		stuff->fdf.k = (stuff->fdf.k + 0.001 * stuff->fdf.maxy);
	}
	return (0);
}
