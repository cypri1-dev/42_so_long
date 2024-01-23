# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:46:52 by cyferrei          #+#    #+#              #
#    Updated: 2024/01/16 17:05:07 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_itoa.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strrchr.c \
		get_next_line_utils.c \
		get_next_line.c \
		print_char.c \
		print_hexa.c \
		print_int.c \
		print_percent.c \
		print_pointer.c \
		print_string.c \
		print_unsigned.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_putnbr_fd.c \
		ft_split.c

NAME = libft_so_long.a
OBJS = $(SRC:.c=.o)
CC = cc
RM = rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = libft_so_long.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILE)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re