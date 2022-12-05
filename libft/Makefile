# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 11:58:02 by meshahrv          #+#    #+#              #
#    Updated: 2022/12/05 23:14:24 by meshahrv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH	= src_libft/
OBJ_PATH	= obj_libft_gnl/
GNL_PATH	= get_next_line/

SRC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRC_GNL = get_next_line_bonus.c\
			get_next_line_utils_bonus.c
			
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
GNL			= $(addprefix $(GNL_PATH), $(SRC_GNL))
OBJ			= $(SRC:.c=.o)
OBJS_GNL 	= $(SRC_GNL:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ) $(OBJS_GNL))
DEPS		= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INCS	= -I./includes_libft/

# DEPS = ${SRC:.c=.d}
# INCS = -I ./includes_libft/

# BONUS_OBJ = $(BONUS_SRC:.c=.o)

COMPILER_COMMAND = cc

CFLAGS = -Wall -Werror -Wextra -g3 -MMD -MP

AR = ar rcs

RM = rm -rf

####### COLORS #######

GREEN = "\033[38;5;150m"
CYAN = "\033[38;5;140m"
BOLD = "\033[1m"
NC = "\033[0m"

# %.o: %.c 
#	@$(COMPILER_COMMAND) $(CFLAGS) ${INCS} -c $< -o $@

all:	$(NAME)

# $(NAME): $(OBJS)
# 	@$(AR) $(NAME) $(OBJS)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Compiling Libft Objects ${NC}
	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Compiling Get Next Line Objects ${NC}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(GNL_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

clean:
	@$(RM) ${OBJ_PATH}

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

-include ${DEPS}

.PHONY : all clean fclean re