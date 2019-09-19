/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:53:58 by thberrid          #+#    #+#             */
/*   Updated: 2019/01/06 16:36:31 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef	struct	s_piece {
	int				x;
	int				y;
	int				width;
	int				height;
	unsigned short	shape;
	char			name;
}				t_piece;

void			reset_coord(t_piece *tab);
void			update_coord(t_piece *tab, int side);
int				countpieces(t_piece *tab);
void			make_copy(unsigned int *dest, unsigned int *src);
void			ft_printexit(int test);
void			ft_printusage(void);
void			printboard(int side, t_piece *tab);
void			verify(char *str, t_piece *tab);
void			new_bloc(char *buff, t_piece *bloc, int d);
void			resolve(t_piece *tab);
#endif
