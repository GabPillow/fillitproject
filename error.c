/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:51:22 by thberrid          #+#    #+#             */
/*   Updated: 2018/12/18 18:46:52 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printexit(int c)
{
	if (c == 1)
		return ;
	ft_putendl("error");
	exit(-1);
}

void	ft_printusage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(-1);
}
