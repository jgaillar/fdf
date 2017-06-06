/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:35:17 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/27 00:26:53 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1920
# define LENGTH 1080
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define ALIAS(var, name) typeof(var) name = var

typedef struct	s_seg
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_seg;

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			size;
	int			color;
	char		*data;
}				t_img;

typedef struct	s_fdf
{
	int			x;
	int			y;
	float		k;
	int			maxx;
	int			maxy;
	float		padding;
	float		hpadding;
	float		gpadding;
}				t_fdf;

typedef struct	s_pos
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_pos;

typedef	struct	s_stuff
{
	t_seg		seg;
	t_img		img;
	t_fdf		fdf;
	t_pos		pos;
	char		buf[BUFF_SIZE + 1];
	int			**array;
	int			**backup;
	int			fd;
}				t_stuff;

void			free_2d(char **array);
char			*ft_strstrip(char *str, char c);
void			ft_exit(int code);
int				img(t_stuff *stuff);
int				get_next_line(const int fd, char **line);
size_t			lentab(char *buf);
int				**malloc2d(t_fdf *fdf);
int				searchbigline(char *buf);
void 			putintab(t_stuff *stuff);
void			init_struct(t_stuff *stuff);
void			ft_segment(t_stuff stuff);
void			mlx_pixel_put_to_image(t_img img, int x, int y, int color);
void			*setpoint(t_stuff stuff);
int				exitreset(int keycode, t_stuff *stuff);
int				deplahor(int keycode, t_stuff *stuff);
int				deplaver(int keycode, t_stuff *stuff);
int				zoom(int keycode, t_stuff *stuff);
int				level(int keycode, t_stuff *stuff);
int				hooks(int keycode, t_stuff *stuff);
int				blue(int keycode, t_stuff *stuff);
int				green(int keycode, t_stuff *stuff);
int				red(int keycode, t_stuff *stuff);
int				hooks(int keycode, t_stuff *stuff);
int				controlhelp(int i);
int				ft_strclen(char *str, char c);

#endif
