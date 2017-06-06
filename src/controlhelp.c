/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlhelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/27 00:17:56 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		controlhelp(int i)
{
	ft_putendl("             	   Controls");
	ft_putendl("              Arrow keys to move");
	ft_putendl("   Numpad (+) & (-) to (elevate) or [decrease]");
	ft_putendl("    	 Regular (+) & (-) for the [zoom]");
	ft_putendl("           (ESC) to [exit] the window");
	ft_putendl("             (R) to [reset] the map\n");
	ft_putendl("                      RGB");
	ft_putendl("          Numpad (4), (5) & (6) for [+]");
	ft_putendl("          Numpad (1), (2) & (3) for [-]\n");
	return (i);
}
