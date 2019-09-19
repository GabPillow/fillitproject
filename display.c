/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 19:07:57 by grochefo          #+#    #+#             */
/*   Updated: 2019/01/06 16:32:03 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*put_piecealph(int side, t_piece *tab, char *board)
{
	int j;
	int i;
	int b;

	i = 0;
	while (tab[i].shape)
	{
		b = 0;
		while (b < tab[i].height)
		{
			j = 0;
			while (j < tab[i].width)
			{
				if (tab[i].shape >> (j + 4 * b) & 0x0001)
					board[(j + (side + 1) * b) + (((side + 1)
								* tab[i].y) + tab[i].x)] = tab[i].name;
				j++;
			}
			b++;
		}
		i++;
	}
	return (board);
}

void	printboard(int side, t_piece *tab)
{
	int		j;
	char	board[side * side + side + 1];
	int		size;

	size = side * side + side + 1;
	j = size - 1;
	while (j--)
		board[j] = '.';
	put_piecealph(side, tab, board);
	j = side;
	while (j < size)
	{
		board[j] = '\n';
		j += side + 1;
	}
	board[size] = '\0';
	ft_putstr(board);
}
