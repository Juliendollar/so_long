# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:26:43 by jd-halle          #+#    #+#              #
#    Updated: 2024/07/21 21:11:39 by jd-halle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c\
			  ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
			  ft_memmove.c ft_putnbr_fd.c ft_strlen.c ft_strrchr.c \
			  ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c ft_memset.c  \
			  ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
			  ft_strcmp.c ft_count_number.c ft_atol.c libftprintf.c putnbr.c \
			  get_next_line.c get_next_line_utils.c ft_strdup.c ft_strchr.c
OBJS			= $(SRCS:.c=.o)

BONUS			= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
