/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 18:47:47 by grochefo          #+#    #+#             */
/*   Updated: 2019/01/06 16:41:15 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_piece(t_piece piece, int x, int y, unsigned int *board)
{
	int i;
	int h;

	h = 0;
	while (h < piece.height)
	{
		i = 0;
		while (i < piece.width)
		{
			if ((piece.shape >> (i + 4 * h) & 0x0001) &&
					(board[y + h] >> (i + x) & 0x0001))
				return (0);
			if (piece.shape >> (i + 4 * h) & 0x0001)
				board[y + h] += (unsigned int)ft_power(2, i + x);
			i++;
		}
		h++;
	}
	return (1);
}

int		put_piece(t_piece *piece, unsigned int *board, int side)
{
	unsigned int	board_copy[32];

	make_copy(board_copy, board);
	while (piece->y <= side - piece->height)
	{
		while (piece->x <= side - piece->width)
		{
			if (try_piece(*piece, piece->x, piece->y, board_copy))
			{
				make_copy(board, board_copy);
				return (1);
			}
			make_copy(board_copy, board);
			piece->x++;
		}
		piece->x = 0;
		piece->y++;
	}
	return (0);
}

int		find_path(int side, unsigned int *board, t_piece *tab, int i)
{
	unsigned int	board_copy[32];

	make_copy(board_copy, board);
	tab[i].x = 0;
	tab[i].y = 0;
	while (put_piece(&(tab[i]), board_copy, side))
	{
		if (!tab[i + 1].shape)
		{
			make_copy(board, board_copy);
			return (1);
		}
		if (find_path(side, board_copy, tab, i + 1))
		{
			make_copy(board, board_copy);
			return (1);
		}
		make_copy(board_copy, board);
		update_coord(&(tab[i]), side);
	}
	return (0);
}

void	resolve(t_piece *tab)
{
	unsigned int	board[32];
	int				nb_pieces;
	int				side;
	int				i;

	nb_pieces = countpieces(tab);
	i = 32;
	while (i--)
		board[i] = 0;
	while (!(side = ft_sqrt(nb_pieces)))
		nb_pieces++;
	while (!find_path(side, board, tab, 0))
	{
		side++;
		i = 32;
		while (i--)
			board[i] = 0;
		i = 0;
		reset_coord(tab);
	}
	printboard(side, tab);
}
