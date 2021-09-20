# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:37:38 by jberredj          #+#    #+#              #
#    Updated: 2021/09/20 17:49:43 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHK_NAME	=	checker

CC			=	clang
OPTI		=	-O2
CFLAGS		=	-Wall -Wextra -Werror $(OPTI)

SRC_DIR		= 	srcs
INC_DIR		=	includes
OBJ_DIR		=	objs

###############################################################################
##								Source files								 ##
###############################################################################

STRUCTS		=	t_stack.h
HEADERS		=	$(addprefix structs/, $(STRUCTS)) \
				checker.h insertion_sort.h math_stats.h ps_mv.h push_swap.h \
				sorters.h

CHECKER		=	checker_main.c check_sort.c
PUSH_SWAP	=	ps_main.c
SORTERS		=	find_lowest_move.c insertion_sort.c lower_sort.c sort_utils.c \
				sort_utils2.c test_move.c 
PS_MV		=	p.c r.c rr.c s.c
COMMON		=	init_stacks.c

PS_SRCS		=	$(addprefix srcs/push_swap/, $(PUSH_SWAP)) \
				$(addprefix srcs/sorters/, $(SORTERS)) 
PS_OBJS		=	$(addprefix objs/, $(notdir $(PS_SRCS:.c=.o)))

COM_SRCS	=	$(addprefix srcs/common/, $(COMMON)) \
				$(addprefix srcs/ps_mv/, $(PS_MV)) 
COM_OBJS	=	$(addprefix objs/, $(notdir $(COM_SRCS:.c=.o)))

CHK_SRCS	=	$(addprefix srcs/checker/, $(CHECKER)) 
CHK_OBJS	=	$(addprefix objs/, $(notdir $(CHK_SRCS:.c=.o)))

LIBS		=	libft.a

###############################################################################
##							Color output char								 ##
###############################################################################
BLUE			=\033[0;34m
NC				=\033[0m
LIGHT_PURPLE	=\033[1;35m
GREEN			=\033[0;32m
RED				=\033[0;31m

###############################################################################
## 							Mandatory recipes								 ##
###############################################################################

all: $(NAME)

$(NAME): $(LIBS) $(OBJ_DIR) $(PS_OBJS) $(COM_OBJS)
	printf "$(BLUE)Linking $(LIGHT_PURPLE)$(NAME) $(BLUE)executable$(NC)\n"
	$(CC) $(CFLAGS) -I $(INC_DIR) $(PS_OBJS) $(COM_OBJS) $(LIBS) \
		-lXext -lX11 -lm -lbsd -o $(NAME)
	printf "$(GREEN)Completed$(NC)\n"

clean:
	printf "$(RED)Removing objects files$(NC)\n"
	rm -rf objs
	rm -rf *.o;

fclean: clean
	printf "$(RED)Removing $(LIGHT_PURPLE)$(NAME) \
	$(RED)executable\nRemoving libraries$(NC)\n"	
	rm -rf $(NAME)
	rm -rf $(CHK_NAME)
	rm -rf $(LIBS)

re: fclean all

###############################################################################
## 								Extra recipes								 ##
###############################################################################

ffclean: fclean
	make -C libs/libft fclean

$(CHK_NAME): $(LIBS) $(OBJ_DIR) $(CHK_OBJS) $(COM_OBJS)
	printf "$(BLUE)Linking $(LIGHT_PURPLE)checker $(BLUE)executable$(NC)\n"
	$(CC) $(CFLAGS) -I $(INC_DIR) $(CHK_OBJS) $(COM_OBJS) $(LIBS) \
		-lXext -lX11 -lm -lbsd -o $(CHK_NAME)
	printf "$(GREEN)Completed$(NC)\n"

$(COM_OBJS): $(COM_SRCS)
	printf "$(BLUE)Compiling $(LIGHT_PURPLE)common $(BLUE)sources$(NC)\n"
	find ./objs/ -type f -exec touch {} +
	$(foreach source,$?, \
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $(source);printf "Compiling $(LIGHT_PURPLE) \
	$(notdir $(source) $(NC)\n");)
	mv -f $(notdir $(?:.c=.o)) objs/

$(PS_OBJS): $(PS_SRCS)
	printf "$(BLUE)Compiling $(LIGHT_PURPLE)$(NAME) $(BLUE)sources$(NC)\n"
	find ./objs/ -type f -exec touch {} +
	$(foreach source,$?, \
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $(source);printf "Compiling $(LIGHT_PURPLE) \
	$(notdir $(source) $(NC)\n");)
	mv -f $(notdir $(?:.c=.o)) objs/

$(CHK_OBJS): $(CHK_SRCS)
	printf "$(BLUE)Compiling $(LIGHT_PURPLE)checker $(BLUE)sources$(NC)\n"
	find ./objs/ -type f -exec touch {} +
	$(foreach source,$?, \
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $(source);printf "Compiling $(LIGHT_PURPLE) \
	$(notdir $(source) $(NC)\n");)
	mv -f $(notdir $(?:.c=.o)) objs/

libft.a:
	make -C libs/libft
	cp libs/libft/libft.a .

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
.SILENT:

###############################################################################
## 								Norm recipe									 ##
###############################################################################

norm:
	printf "$(BLUE)Checking norm$(NC)\n"
	norminette $(PS_SRCS) $(COM_SRCS) $(CHK_SRCS) \
	$(addprefix $(INC_DIR)/, $(HEADERS)) libs/libft ; if [ "$$?" -ne "0" ]; \
	then printf "$(RED)NORM ERROR$(NC)\n"; \
	else printf "$(GREEN)NORM OK$(NC)\n";fi