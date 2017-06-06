/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:53:21 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/09 11:19:48 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t		lentab(char *buf)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			len++;
		i++;
	}
	if (buf[i] == '\0' && buf[i - 1] != '\n')
		len++;
	return (len);
}


void 	putintab(t_stuff *stuff)
{
	int	i;
	int j;
	char **tmp;
	char **tmp2;

	ALIAS(stuff->array, array);
	if (!array)
		exit(0);
	i = -1;
	tmp = ft_strsplit(stuff->buf, '\n');
	while (++i < stuff->fdf.maxy)
	{
		j = -1;
		tmp2 = ft_strsplit(tmp[i], ' ');
		while (++j < stuff->fdf.maxx)
		{
			if (tmp2[j] == NULL)
				break ;
			array[i][j] = ft_atoi(tmp2[j]);
		}
		free_2d(tmp2);
	}
	free_2d(tmp);
}
