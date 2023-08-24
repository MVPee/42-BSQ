# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 09:12:03 by mvpee             #+#    #+#              #
#    Updated: 2023/08/22 15:42:32 by mvan-pee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS = $(addprefix $(SRCDIR)/, \
	main.c \
	fonctions/ft_createfolder.c \
	fonctions/ft_atoi.c \
	fonctions/ft_putchar.c \
	fonctions/ft_putstr.c \
	fonctions/ft_strlen.c \
	fonctions/ft_strcpy.c \
	fonctions/ft_split.c \
	fonctions/ft_tableout.c \
	fonctions/ft_folderout.c \
	fonctions/ft_is_numeric.c \
	fonctions/open_file.c \
	fonctions/read_file.c \
	algorythm/ft_solve.c \
	algorythm/ft_casevalue.c \
	algorythm/ft_higher_value.c \
	algorythm/ft_get_cord.c \
	algorythm/ft_print_map.c \
	algorythm/ft_map_validity.c \
)

NAME = bsq

RM = rm -f

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re