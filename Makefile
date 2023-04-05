# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 14:40:39 by kamitsui          #+#    #+#              #
#    Updated: 2023/04/05 15:01:26 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files and Target
SRCS = \
	   get_next_line.c \
	   get_next_line_utils.c \
	   test/gnl_test.c
NAME = a.out

# Test case
FILES_DIR = files
FILES = nl
BUFFER_SIZE = 1

# Compiler
CC = clang
CFLAGS = -Wall -Wextra -Werror -I. -D BUFFER_SIZE=$(BUFFER_SIZE) -g

# Default target
all:$(NAME)
	./$(NAME) $(FILES_DIR)/$(FILES)

# Target
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	$(RM) $(NAME)

.PHONY: all clean
