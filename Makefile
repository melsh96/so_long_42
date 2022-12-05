# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 17:58:22 by meshahrv          #+#    #+#              #
#    Updated: 2022/12/05 13:19:01 by meshahrv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_PATH	= src/
OBJ_PATH	= obj/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -g3

SRC = main.c \
		init.c \
		utils.c \
		moves.c \
		checkers.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
DEPS	= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS	= -I./includes/ -I./minilibx-linux/
LIB 	= -L./libft/ -lft

RM = rm -rf

####### COLORS #######

GREEN = "\033[38;5;150m"
CYAN = "\033[38;5;140m"
BOLD = "\033[1m"
NC = "\033[0m"

all:	${NAME}

${NAME}: ${OBJS}
	make --no-print-directory header
	@make --no-print-directory -C minilibx-linux all
	@make --no-print-directory -C libft
	@${CC} $(CFLAGS) ${OBJS} ${LIB} -o ${NAME} -Lminilibx-linux -lmlx -lXext -lX11
	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Compiling So_Long Objects ${NC}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

clean:
	@make $@ --no-print-directory -C minilibx-linux clean
	@${RM} ${OBJ_PATH}
	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Cleaning Objects ${NC}

fclean:	clean
	@make $@ --no-print-directory -C libft
	@rm -f ${NAME}
	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Cleaning All ${NC}

re: fclean all

define HEADER
\033[38;5;140m
   _|_|_|    _|_|      _|          _|_|    _|      _|    _|_|_|  
 _|        _|    _|    _|        _|    _|  _|_|    _|  _|        
   _|_|    _|    _|    _|        _|    _|  _|  _|  _|  _|  _|_|  
       _|  _|    _|    _|        _|    _|  _|    _|_|  _|    _|  
 _|_|_|      _|_|      _|_|_|_|    _|_|    _|      _|    _|_|_|  
                                                                 
                 _|_|_|_|_|                                      
\033[0m                                                                                                           
endef
export HEADER

header :
	clear
	@echo "$$HEADER"

-include ${DEPS}

.SECONDARY : ${OBJS} ${OBJ_PATH} ${OBJ}

.PHONY : all clean fclean re