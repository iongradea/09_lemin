# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igradea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 19:01:51 by igradea           #+#    #+#              #
#    Updated: 2018/03/08 15:16:19 by igradea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

# Source files
LBFT_SRC := ft_realloc.c ft_isspace.c	ft_isupper.c ft_islower.c	\
            ft_isalpha.c ft_isdigit.c	ft_isalnum.c ft_isascii.c	\
            ft_isprint.c ft_toupper.c	ft_tolower.c ft_memset.c	\
            ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
            ft_memchr.c ft_memcmp.c ft_memalloc.c	ft_memdel.c	\
            ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c	\
            ft_strcat.c ft_strncat.c ft_strlcat.c	ft_strchr.c	\
            ft_strrchr.c ft_strstr.c ft_strnstr.c	ft_strcmp.c	\
            ft_strncmp.c ft_atoi.c ft_strnew.c ft_strdel.c	\
            ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c	\
            ft_strmapi.c ft_strequ.c ft_strnequ.c	ft_strsub.c	\
            ft_strjoin.c ft_strtrim.c	ft_strsplit.c ft_count_nb_words.c	\
            ft_itoa.c	ft_putchar.c ft_putstr.c ft_putendl.c	\
            ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c	\
            ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c	\
            ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
            ft_sqrt.c ft_abs.c ft_max.c ft_print_memory.c ft_itoa_base.c \
            ft_strnjoin.c ft_min.c ft_strndup.c

GNL_SRC := get_next_line.c

PRT_SRC := convert_arg.c parser.c parser_aux.c tools_basic.c \
            parsing_clean.c parsing_clean_flags.c parsing_clean_length.c \
            tools_conv.c d_convert.c str_format.c ft_printf.c \
            tools_atoi_itoa.c u_convert.c s_c_convert.c encode_unicode.c \
            ws_convert.c tools_ws_convert.c parsing_clean_special.c \
            ft_printf_aux.c

# Directories
LBFT_SRC_DIR := lbft_src
GNL_SRC_DIR := gnl_src
PRT_SRC_DIR := prt_src
OBJ_DIR := bin
INC_DIR := inc

# Flags, libraries, include
# Several compile modes are defined: no flags, debug, standard
ifdef MODE
ifeq ($(MODE), no)
endif
ifeq ($(MODE), debug)
	CFLAGS = -g
endif
ifeq ($(MODE), bug_address)
	CFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
endif

# Variables
LBFT_OBJ := $(LBFT_SRC:.c=.o)
GNL_OBJ := $(GNL_SRC:.c=.o)
PRT_OBJ := $(PRT_SRC:.c=.o)
OBJ := $(LBFT_OBJ) $(GNL_OBJ) $(PRT_OBJ)

all: $(NAME)

# .o files are in a subdirectory
./$(OBJ_DIR)/%.o: ./$(LBFT_SRC_DIR)/%.c ./$(INC_DIR)/libft.h
	@mkdir ./$(OBJ_DIR) 2> /dev/null || true
	gcc $(CFLAGS) -c $< -o $@

./$(OBJ_DIR)/%.o: ./$(GNL_SRC_DIR)/%.c ./$(INC_DIR)/get_next_line.h
	gcc $(CFLAGS) -c $< -o $@

./$(OBJ_DIR)/%.o: ./$(PRT_SRC_DIR)/%.c ./$(INC_DIR)/ft_printf.h
	gcc $(CFLAGS) -c $< -o $@

# Creates library and index
$(NAME): $(addprefix ./$(OBJ_DIR)/, $(OBJ))
	ar rc $(NAME) $(addprefix ./$(OBJ_DIR)/, $(OBJ))
	ranlib $(NAME)

clean:
	/bin/rm -f $(addprefix ./$(OBJ_DIR)/, $(OBJ))
	@rmdir ./$(OBJ_DIR) 2> /dev/null || true

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# Non-file targets
.PHONY: all, re, clean, fclean
