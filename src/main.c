/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:31:45 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/15 22:26:06 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				refresh(t_stuff *stuff)
{
	mlx_destroy_image(stuff->img.mlx_ptr, stuff->img.img_ptr);
	stuff->img.img_ptr = mlx_new_image(stuff->img.mlx_ptr, WIDTH, LENGTH);
	stuff->img.data = mlx_get_data_addr(stuff->img.img_ptr, \
		&stuff->img.bits_per_pixel, &stuff->img.size_line, &stuff->img.endian);
	setpoint(*stuff);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
	return (0);
}

int				img(t_stuff *stuff)
{
	stuff->img.img_ptr = mlx_new_image(stuff->img.mlx_ptr, WIDTH, LENGTH);
	if (!(stuff->img.data = (char *)ft_strnew(sizeof(char)\
		* WIDTH * LENGTH * 4)))
		return (-1);
	stuff->img.data = mlx_get_data_addr(stuff->img.img_ptr,\
		&stuff->img.bits_per_pixel, &stuff->img.size_line, &stuff->img.endian);
	setpoint(*stuff);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
	return (0);
}

void			ft_exit(int code)
{
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

static void		ft_usage(void)
{
	ft_putendl("Usage: ./fdf <map>");
	ft_exit(0);
}

int				main(int ac, char **av)
{
	t_stuff stuff;

	if (ac != 2 || !av[1])
		ft_usage();
	if ((stuff.fd = open(av[1], O_RDONLY)) < 0)
		ft_exit(-1);
	stuff.buf[read(stuff.fd, stuff.buf, BUFF_SIZE)] = '\0';
	close(stuff.fd);
	init_struct(&stuff);
	putintab(&stuff);
	img(&stuff);
	controlhelp(0);
	mlx_hook(stuff.img.win_ptr, 2, (1l << 0), hooks, &stuff);
	mlx_loop(stuff.img.mlx_ptr);
	return (0);
}
