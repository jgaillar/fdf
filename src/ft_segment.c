/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:04:42 by jgaillar          #+#    #+#             */
/*   Updated: 2017/04/07 13:05:20 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_segment(t_stuff stuff)
{
	stuff.seg.dx = ft_abs(stuff.pos.x1 - stuff.pos.x0);
	stuff.seg.sx = (stuff.pos.x0 < stuff.pos.x1 ? 1 : -1);
	stuff.seg.dy = ft_abs(stuff.pos.y1 - stuff.pos.y0);
	stuff.seg.sy = (stuff.pos.y0 < stuff.pos.y1 ? 1 : -1);
	stuff.seg.err = (stuff.seg.dx > stuff.seg.dy \
	? stuff.seg.dx : -stuff.seg.dy) / 2;
	while (1)
	{
		mlx_pixel_put_to_image(stuff.img, stuff.pos.x0, stuff.pos.y0, \
			mlx_get_color_value(stuff.img.mlx_ptr, stuff.img.color));
		if (stuff.pos.x0 == stuff.pos.x1 && stuff.pos.y0 == stuff.pos.y1)
			break ;
		stuff.seg.e2 = stuff.seg.err;
		if (stuff.seg.e2 > -stuff.seg.dx)
		{
			stuff.seg.err -= stuff.seg.dy;
			stuff.pos.x0 += stuff.seg.sx;
		}
		if (stuff.seg.e2 < stuff.seg.dy)
		{
			stuff.seg.err += stuff.seg.dx;
			stuff.pos.y0 += stuff.seg.sy;
		}
	}
}

void			mlx_pixel_put_to_image(t_img img, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIDTH * LENGTH * img.bits_per_pixel / 8;
	if (x < 0 || y < 0 || y * img.size_line + x * img.bits_per_pixel / 8 > \
		img_size
		|| x >= img.size_line / (img.bits_per_pixel / 8) || y >= img_size / \
		img.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = img.bits_per_pixel / 8;
	img.data[y * img.size_line + x * bit_pix] = color1;
	img.data[y * img.size_line + x * bit_pix + 1] = color2;
	img.data[y * img.size_line + x * bit_pix + 2] = color3;
}

static void		sethorpoint(t_stuff *stuff)
{
	stuff->pos.x1 = stuff->fdf.gpadding + (stuff->fdf.padding *
		((stuff->fdf.x + (stuff->fdf.k *
			stuff->array[stuff->fdf.y][stuff->fdf.x + 1]) + 1)));
	stuff->pos.y1 = stuff->fdf.hpadding + (stuff->fdf.padding *
		(stuff->fdf.y + (stuff->fdf.k *
			-stuff->array[stuff->fdf.y][stuff->fdf.x + 1])));
	ft_segment(*stuff);
}

static void		setverpoint(t_stuff *stuff)
{
	stuff->pos.x1 = stuff->fdf.gpadding + (stuff->fdf.padding *
		(stuff->fdf.x + (stuff->fdf.k *
			stuff->array[stuff->fdf.y + 1][stuff->fdf.x])));
	stuff->pos.y1 = stuff->fdf.hpadding + (stuff->fdf.padding *
		((stuff->fdf.y + (stuff->fdf.k *
			-stuff->array[stuff->fdf.y + 1][stuff->fdf.x])) + 1));
	ft_segment(*stuff);
}

void			*setpoint(t_stuff stuff)
{
	stuff.fdf.y = -1;
	while (++stuff.fdf.y != stuff.fdf.maxy)
	{
		stuff.fdf.x = -1;
		while (++stuff.fdf.x != stuff.fdf.maxx)
		{
			stuff.pos.x0 = stuff.fdf.gpadding + (stuff.fdf.padding * (stuff.fdf.
				x + (stuff.fdf.k * stuff.array[stuff.fdf.y][stuff.fdf.x])));
			stuff.pos.y0 = stuff.fdf.hpadding + (stuff.fdf.padding * (stuff.fdf.
				y + (stuff.fdf.k * -stuff.array[stuff.fdf.y][stuff.fdf.x])));
			if (stuff.fdf.x + 1 != stuff.fdf.maxx)
				sethorpoint(&stuff);
			if (stuff.fdf.y + 1 != stuff.fdf.maxy)
				setverpoint(&stuff);
		}
	}
	return (NULL);
}
