# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 13:14:00 by thberrid          #+#    #+#              #
#    Updated: 2019/01/06 16:47:47 by grochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = fillit
FILES_C =	fillit.c error.c verify.c create_bloc.c resolve.c display.c \
			completepiece.c
FILES_O = $(patsubst %.c, %.o, $(FILES_C))
FLAGS = -Wall -Wextra -Werror

.SILENT : clean fclean $(NAME) re all
.PHONY : clean re

all : $(NAME)

$(NAME) : $(FILES_C)
	make -C libft
	gcc -c $(FLAGS) $(FILES_C) -I . -I libft
	gcc $(FLAGS) $(FILES_O) -L libft/ -lft -o $(NAME)
	echo "$(NAME) compiled."

clean :
	rm -f $(FILES_O)	
	make clean -C libft
	echo "*.o removed"

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	echo "EXE removed"

re : fclean all
