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
	if (stuff->img.img_ptr)
		mlx_destroy_image(stuff->img.mlx_ptr, stuff->img.img_ptr);
	img(stuff);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
	return (0);
}

int		exitreset(int keycode, t_stuff *stuff)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
	{
		if (stuff->img.img_ptr)
			mlx_destroy_image(stuff->img.mlx_ptr, stuff->img.img_ptr);
		init_struct(stuff);
		img(stuff);
	}
	return (0);
}

int     ft_strclen(char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i++])
		if (str[i] != c && str[i] != '\n')
			j++;
	return (j);
}

char    *ft_strstrip(char *str, char c)
{
	char	*format;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(format = (char*)ft_strnew(sizeof(char) * ft_strclen(str, c))))
		ft_exit(-1);
	while (str[++i])
		if (str[i] != c)
			format[j++] = str[i];
	format[j] = '\0';
	return (format);
}
