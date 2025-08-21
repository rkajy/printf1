# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 18:42:51 by radandri          #+#    #+#              #
#    Updated: 2025/08/21 17:05:20 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
       ft_utils_az.c \
       ft_utils_numbers.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
# build libft
	$(MAKE) -C $(LIBFT_DIR)
# create the archive libftprint.a
	ar rcs $(NAME) $(OBJS)
# extract libft.o files
	ar -x $(LIBFT)
# add them into libftprint.a archive
	ar rcs $(NAME) *.o
# clean up extracted libft.o files
	rm -f *.o

#bonus:

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	rm -rf "__.SYMDEF SORTED"
	
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
