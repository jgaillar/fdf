/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:53:44 by jgaillar          #+#    #+#             */
/*   Updated: 2017/04/05 16:54:41 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct(t_stuff *stuff)
{
	stuff->fdf.maxx = searchbigline(stuff->buf);
	stuff->fdf.maxy = lentab(stuff->buf);
	stuff->fdf.k = 0.005 * stuff->fdf.maxy;
	stuff->fdf.padding = (WIDTH + LENGTH) / ((stuff->fdf.maxx + \
		stuff->fdf.maxy) * 2.0);
	stuff->fdf.hpadding = (WIDTH / (stuff->fdf.maxy));
	stuff->fdf.gpadding = (LENGTH / (stuff->fdf.maxx) * (stuff->fdf.maxy / 2));
	stuff->img.color = 0x222222;
	if (!(stuff->img.mlx_ptr) && (!stuff->img.win_ptr))
	{
		stuff->img.mlx_ptr = mlx_init();
		stuff->img.win_ptr = mlx_new_window(stuff->img.mlx_ptr, WIDTH, LENGTH,\
			"fdf");
		controlhelp(0);
		stuff->array = malloc2d(&stuff->fdf);
	}
}
