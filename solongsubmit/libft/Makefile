# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:16:37 by lhagemos          #+#    #+#              #
#    Updated: 2024/08/22 13:35:00 by lhagemos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_strlen.c \
ft_tolower.c \
ft_toupper.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_atoi.c \
ft_memset.c \
ft_bzero.c \
ft_memchr.c \
ft_memcpy.c \
ft_memcmp.c \
ft_memmove.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_itoa.c \
ft_striteri.c \
ft_strmapi.c \
ft_printf.c \
ft_putc.c \
ft_puthexa_lw.c \
ft_puthexa_up.c \
ft_putint.c \
ft_putptr.c \
ft_putstring.c \
ft_putu.c

SRC_BONUS = ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstlast.c \
ft_lstnew.c \
ft_lstsize.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

bonus: $(OBJ_BONUS) $(OBJ)
	ar -rcs $(NAME) $^

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
