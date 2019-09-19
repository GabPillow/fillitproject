/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:01:32 by thberrid          #+#    #+#             */
/*   Updated: 2019/01/06 17:20:21 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checklinks(char *buff, int i)
{
	int links;

	links = 0;
	if (i + 5 < 20 && buff[i + 5] == '#')
		links++;
	if (i - 5 >= 0 && buff[i - 5] == '#')
		links++;
	if (i + 1 < 20 && buff[i + 1] == '#')
		links++;
	if (i - 1 >= 0 && buff[i - 1] == '#')
		links++;
	return (links);
}

static void		ft_checksyntax(char *buff)
{
	int		i;
	int		sharp_nbr;
	int		links;

	links = 0;
	i = 0;
	sharp_nbr = 0;
	while (i < 20)
	{
		if (i > 0 && (i + 1) % 5 == 0)
			ft_printexit(buff[i] == '\n');
		else
		{
			ft_printexit(buff[i] == '.' || buff[i] == '#');
			if (buff[i] == '#')
			{
				links += ft_checklinks(buff, i);
				sharp_nbr += 1;
			}
		}
		i += 1;
	}
	ft_printexit(links >= 6 && links <= 8);
	ft_printexit(sharp_nbr == 4);
}

void			verify(char *str, t_piece *tab)
{
	char	buff[20];
	int		fd;
	int		i;
	int		ret;

	ft_printexit((fd = open(str, O_RDONLY)) > 0);
	i = 0;
	while ((ret = read(fd, buff, 20)) == 20)
	{
		ft_checksyntax(buff);
		ft_printexit(i != 26);
		new_bloc(buff, &(tab[i]), i);
		i++;
		if ((ret = read(fd, buff, 1)))
			ft_printexit(ret && buff[0] == '\n');
	}
	ft_printexit(countpieces(tab) != 0);
	ft_printexit(ret == 0 && buff[0] != '\n');
	close(fd);
}
