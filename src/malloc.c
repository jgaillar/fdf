/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:28:34 by jgaillar          #+#    #+#             */
/*   Updated: 2017/04/04 13:30:06 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**malloc2d(t_fdf *fdf)
{
	int		**array;
	int		i;

	i = -1;
	if (!(array = (int **)ft_memalloc(sizeof(int *) * (fdf->maxy))))
		exit(0);
	while (++i < fdf->maxy)
		if (!(array[i] = (int *)ft_memalloc(sizeof(int) * (fdf->maxx))))
			exit(0);
	return (array);
}

int		searchbigline(char *buf)
{
	int		i;
	int		len;
	int		big;

	i = -1;
	len = 0;
	big = 0;
	while (buf[++i])
	{
		if (buf[i] != ' ' && buf[i] != '\n')
		{
			len++;
			while (buf[i] != ' ' && buf[i] != '\n')
				i++;
		}
		if (buf[i] == '\n')
		{
			if (big < len)
				big = len;
			len = 0;
		}
	}
	return (big >= len ? big : len);
}

void	free_2d(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		ft_strdel(&array[i]);
	free(array);
	array = NULL;
}
