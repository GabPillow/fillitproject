/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:42:15 by thberrid          #+#    #+#             */
/*   Updated: 2019/01/06 15:09:18 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_piece tab[27];
	int		i;

	if (ac == 2)
	{
		i = 26;
		while (i--)
			tab[i].shape = 0;
		verify(av[1], tab);
		resolve(tab);
	}
	else
		ft_printusage();
	return (0);
}
