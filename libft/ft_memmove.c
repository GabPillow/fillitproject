/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thberrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:03:26 by thberrid          #+#    #+#             */
/*   Updated: 2018/11/20 21:40:55 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bytsmove(void *dst, const void *src, size_t len, int sign)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((char *)dst + (i * sign)) = *((char *)src + (i * sign));
		i += 1;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		dst += (len - 1);
		src += (len - 1);
		ft_bytsmove(dst, src, len, -1);
		dst -= (len - 1);
	}
	else
		ft_bytsmove(dst, src, len, 1);
	return (dst);
}
