/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:01:28 by grochefo          #+#    #+#             */
/*   Updated: 2018/12/17 20:36:49 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t n)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_strnew(n)))
		return (NULL);
	ft_strncpy(dest, src, n);
	return (dest);
}
