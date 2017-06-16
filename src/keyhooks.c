/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:32:01 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/25 13:32:12 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		hooks(int keycode, t_stuff *stuff)
{
	deplahor(keycode, stuff);
	deplaver(keycode, stuff);
	zoom(keycode, stuff);
	level(keycode, stuff);
	blue(keycode, stuff);
	green(keycode, stuff);
	red(keycode, stuff);
	exitreset(keycode, stuff);
	refresh(stuff);
	return (0);
}

int		exitreset(int keycode, t_stuff *stuff)
{
	if (keycode == 53)
	{
		ft_strdel(&stuff->img.data);
		exit(0);
	}
	if (keycode == 15)
		init_struct(stuff);
	return (0);
}
