# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:37:38 by jberredj          #+#    #+#              #
#    Updated: 2021/09/03 11:38:19 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	clang
OPTI		=	-O3
DEBUG		=	-g -Wunused-function
CFLAGS		=	-Wall -Wextra -Werror $(OPTI) $(DEBUG)

HEADERS		=	-I includes

PUSH_SWAP	=	ps_main.c
SORTERS		=	find_lowest_move.c insertion_sort.c lower_sort.c sort_utils.c sort_utils2.c test_move.c 
PS_MV		=	p.c r.c rr.c s.c

PS_SRCS		=	$(PUSH_SWAP) $(PS_MV)
PS_OBJS		=	$(PS_SRCS:.c=.o)
PS_MODULE	=	push_swap ps_mv sorters

CHK_SRCS	=	$(PS_MV)
CHK_OBJS	=	$(CHK_SRCS:.c=.o)
CHK_MODULE	=	ps_mv

LIBS		=	libft.a

all: $(NAME)

$(NAME): $(PS_MODULE) $(LIBS)
	$(CC) $(CFLAGS) $(HEADERS) $(addprefix objs/, $(PS_OBJS)) $(LIBS) -o $(NAME)

checker: $(CHK_MODULE) $(LIBS)
	$(CC) $(CFLAGS) $(HEADERS) $(addprefix objs/, $(CHK_OBJS)) $(LIBS) -o checker

push_swap: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/push_swap/, $(PUSH_SWAP))
	mv *.o objs

sorters: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/sorters/, $(SORTERS))
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