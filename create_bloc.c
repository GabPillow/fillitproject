/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:26:18 by grochefo          #+#    #+#             */
/*   Updated: 2019/01/06 16:36:14 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_getwidth(char *buff)
{
	int		i;
	int		line_nbr;
	int		extremleft;
	int		extremright;

	line_nbr = 0;
	i = 0;
	extremleft = 3;
	extremright = 0;
	while (i < 20)
	{
		if (buff[i] == '\n')
			line_nbr++;
		if (buff[i] == '#')
		{
			if (i - 5 * line_nbr < extremleft)
				extremleft = i - 5 * line_nbr;
			if (i - 5 * line_nbr > extremright)
				extremright = i - 5 * line_nbr;
		}
		i++;
	}
	return (extremright - extremleft + 1);
}

int				ft_getheight(char *buff)
{
	int		i;
	int		line_nbr_min;
	int		line_nbr_max;

	i = -1;
	line_nbr_min = 0;
	line_nbr_max = 4;
	while (i++ <= 20)
	{
		if (buff[i] == '#')
			break ;
		if (buff[i] == '\n')
			line_nbr_min++;
	}
	i = 19;
	while (i--)
	{
		if (buff[i] == '#')
			break ;
		if (buff[i] == '\n')
			line_nbr_max--;
	}
	return (line_nbr_max - line_nbr_min);
}

short			movetop(unsigned short shape)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (shape >> i & 0x0001)
			return (shape);
		i++;
		if (i == 4)
		{
			shape >>= 4;
			i = 0;
		}
	}
	return (shape);
}

short			moveleft(unsigned short shape)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (shape >> i & 0x0001)
			return (shape);
		i += 4;
		if (i == 16)
		{
			shape >>= 1;
			i = 0;
		}
	}
	return (shape);
}

void			new_bloc(char *buff, t_piece *bloc, int d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	bloc->name = 'A' + d;
	bloc->x = 0;
	bloc->y = 0;
	bloc->width = ft_getwidth(buff);
	bloc->height = ft_getheight(buff);
	bloc->shape = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
			bloc->shape += ft_power(2, j);
		if (buff[i] != '\n')
			j++;
		i++;
	}
	bloc->shape = moveleft(bloc->shape);
	bloc->shape = movetop(bloc->shape);
}
