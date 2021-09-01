# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:37:38 by jberredj          #+#    #+#              #
#    Updated: 2021/09/01 15:04:48 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	clang
OPTI	=	-O3
DEBUG	=	-g -Wunused-function
CFLAGS	=	-Wall -Wextra -Werror $(OPTI) $(DEBUG)

HEADERS	=	-I includes
MODULE	=	main ps_mv

MAIN	=	main.c find_median.c sort_utils.c insertion_sort.c ##half_sort.c quarter_sort.c
PS_MV	=	p.c r.c rr.c s.c

SRCS	=	$(MAIN) $(PS_MV)
OBJS	=	$(SRCS:.c=.o)

LIBS	=	libft.a

all: $(NAME)

$(NAME): $(MODULE) $(LIBS)
	$(CC) $(CFLAGS) $(HEADERS) $(addprefix objs/, $(OBJS)) $(LIBS) -o $(NAME)

main: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/, $(MAIN))
	mv *.o objs

ps_mv: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/ps_mv/, $(PS_MV))
	mv *.o objs

libft.a:
	make -C libs/libft
	cp libs/libft/libft.a .

objs:
	mkdir -p objs/

clean:
	rm -rf objs
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBS)

re: fclean all