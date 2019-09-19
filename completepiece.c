/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completepiece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:47:52 by grochefo          #+#    #+#             */
/*   Updated: 2019/01/06 16:35:58 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_coord(t_piece *tab)
{
	int		i;

	i = 0;
	while (tab[i].shape)
	{
		tab[i].x = 0;
		tab[i].y = 0;
		i++;
	}
}

void	update_coord(t_piece *tab, int side)
{
	tab->x++;
	if (tab->x == side)
	{
		tab->x = 0;
		tab->y++;
	}
}

int		countpieces(t_piece *tab)
{
	int i;

	i = 0;
	while (tab[i].shape)
		i++;
	return (i * 4);
}

void	make_copy(unsigned int *dest, unsigned int *src)
{
	int i;

	i = 33;
	while (i--)
		dest[i] = src[i];
}
