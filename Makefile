# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 21:08:42 by kquetat-          #+#    #+#              #
#    Updated: 2023/05/29 10:04:36 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Binary | libmlx path & .h | libft ###
NAME	=	so_long
HEADER	=	./includes/
LIBFT	=	./libft/libft/
LIBMLX	=	./usr/local/lib/
INC		=	./usr/local/include/

### Paths to main & other functions ###
SRCS_PATH		=	./srcs/
FT_PRINTF_PATH	=	./libft/ft_printf/
GNL_PATH		=	./libft/get_next_line/

### Colors ###
ITALIC		=	\033[3m
BOLD		=	\033[1m
BEIGE		=	\033[38;5;230m
CREAM		=	\033[38;5;255m
IVORY		=	\033[38;5;253m
OFF_WHITE	=	\033[38;5;251m
EGGSHELL	=	\033[38;5;251m
CHAMPAGNE	=	\033[38;5;224m

### Debug ###
ifdef DEBUG
CFLAGS	+=	-fsanitize=address -g3
endif

### Loading Bar ###
COUNTER		=	0
CUR_UP		=	\033[A
TOTAL_SRCS	=	$(shell find . -type f -name "*.c" -not -path "./libft/libft/*" -not -path "./mlx/*" | wc -l)
PERCENT		=	$(shell expr 100 \* $(COUNTER) / $(TOTAL_SRCS))
BAR			=	$(shell expr 27 \* $(COUNTER) / $(TOTAL_SRCS))

### Compilation & flags ###
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OFLAGS	=	-lmlx -framework OpenGL -framework AppKit

RM	=	rm -f

%.o: %.c ${HEADER}
	@$(eval COUNTER = $(shell expr $(COUNTER) + 1))
	@$(CC) $(CFLAGS) -I${HEADER} -c $< -o $@
	@echo " $(PALEBLUE)$(BOLD)$(ITALIC) Loading [$(LGREEN)SO_LONG$(PALEBLUE)]: $(RESET)"
	@printf "\t\t\t$(BOLD)$(PALEBLUE)[$(BEIGE)%-27.$(BAR)s$(PALEBLUE)] %d/%d [%d%%]$(RESET)" "===========================" $(COUNTER) $(TOTAL_SRCS) $(PERCENT)
	@echo "$(CUR_UP)$(CUR_UP)"

### Source Files ###
SRCS	=	${addprefix ${SRCS_PATH}, so_long.c error/error.c init_game/initialize_game.c init_game/p_moves.c \
			init_game/window_tools.c init_game/hook_func.c} \
			${addprefix ${SRCS_PATH}map_utils/, collect_map.c map_tools.c map_tools2.c} \
			${addprefix ${FT_PRINTF_PATH}, ft_printf.c srcs/add_numflags.c srcs/hexa_padd.c \
			srcs/print_char.c srcs/print_str.c srcs/ft_get_precision.c srcs/int_precision.c \
			srcs/print_hexa.c srcs/print_unsigned.c srcs/ft_get_width.c srcs/print_addr.c \
			srcs/print_int.c} \
			${addprefix ${GNL_PATH}, get_next_line.c get_next_line_utils.c}

OBJS	=	$(SRCS:.c=.o)

### Rules ###

all:	$(NAME)

$(NAME):	$(OBJS)
	@printf "\n\n\n"
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OFLAGS) $(LIBFT)libft.a $(OBJS) -o $(NAME)
	@printf "\n\n\t $(BOLD)$(ITALIC)$(EGGSHELL)SO_LONG COMPILED ✨$(RESET)\n\n"

debug:
	$(MAKE) DEBUG=1

clean:
	@$(RM) $(OBJS)
	@printf "\n\t$(BOLD)$(ITALIC)$(OFF_WHITE)[$(BEIGE)SO_LONG$(OFF_WHITE)] .o files $(LGREEN)CLEANED$(RESET)\n"
	@make clean -C $(LIBFT)

fclean:	clean
	@$(RM) $(LIBFT)libft.a $(NAME)
	@printf "\n\t$(BOLD)$(ITALIC)$(OFF_WHITE)[$(BEIGE)SO_LONG$(OFF_WHITE)] $(CHAMPAGNE)executable CLEANED$(RESET)\n\n"

re:	fclean all

.PHONY:	all debug clean fclean re