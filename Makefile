# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 23:03:23 by ksharlen          #+#    #+#              #
#    Updated: 2019/08/11 19:59:28 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_ls
DIR_SRC		:=	src/
DIR_BIN		:=	bin/
DIR_INCLUDE :=	include/
CC			:=	gcc
CFLAGS		:=	-g
HEADERS		:=	libft.h ft_printf.h ft_getopt.h ft_ls.h
LIBFT		:=	libft.a
REMOVE		:=	rm -rf
SRC			:=	main.c\
					ft_ls.c\
					lists.c\
					lists_filename.c\
					other.c

OBJS 		:= $(SRC:.c=.o)
LIBFT		:= $(addprefix $(DIR_SRC), $(LIBFT))

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(addprefix $(DIR_BIN), $(OBJS)) $(LIBFT) -o $@

$(OBJS):%.o:%.c $(HEADERS) | $(DIR_BIN)
	$(CC) -c $(CFLAGS) $< -o $(DIR_BIN)$@ -I $(DIR_INCLUDE)

$(DIR_BIN):
	mkdir -p $@

clean:
	$(REMOVE) $(addprefix $(DIR_BIN), $(OBJS))
	$(REMOVE) $(DIR_BIN)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean all re
.SILENT: all $(NAME) $(OBJS) $(DIR_BIN) clean fclean re