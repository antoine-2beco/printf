# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:52:56 by ade-beco          #+#    #+#              #
#    Updated: 2023/11/08 17:29:29 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		"libftprintf.a"

SRCS 		=		src/ft_printf.c src/ft_printf_utils.c

LIBFT		=		src/libft/ft_isalpha.c src/libft/ft_isdigit.c src/libft/ft_isalnum.c src/libft/ft_isascii.c src/libft/ft_isprint.c src/libft/ft_strlen.c src/libft/ft_memset.c src/libft/ft_bzero.c src/libft/ft_memcpy.c src/libft/ft_memmove.c src/libft/ft_strlcpy.c src/libft/ft_strlcat.c src/libft/ft_toupper.c src/libft/ft_tolower.c src/libft/ft_strchr.c src/libft/ft_strrchr.c src/libft/ft_strncmp.c src/libft/ft_memchr.c src/libft/ft_memcmp.c src/libft/ft_strnstr.c src/libft/ft_atoi.c src/libft/ft_calloc.c src/libft/ft_strdup.c src/libft/ft_substr.c src/libft/ft_strjoin.c src/libft/ft_strtrim.c src/libft/ft_split.c src/libft/ft_itoa.c src/libft/ft_strmapi.c src/libft/ft_striteri.c src/libft/ft_putchar_fd.c src/libft/ft_putstr_fd.c src/libft/ft_putendl_fd.c src/libft/ft_putnbr_fd.c		

LIBFT_BONUS	=		src/libft/ft_lstnew_bonus.c src/libft/ft_lstadd_front_bonus.c src/libft/ft_lstsize_bonus.c src/libft/ft_lstlast_bonus.c src/libft/ft_lstadd_back_bonus.c src/libft/ft_lstdelone_bonus.c src/libft/ft_lstclear_bonus.c src/libft/ft_lstiter_bonus.c src/libft/ft_lstmap_bonus.c

OBJS		=		$(SRCS:.c=.o) $(LIBFT:.c=.o) $(LIBFT_BONUS:.c=.o)

CC			=		cc -Wall -Wextra -Werror -g

LIBC		=		ar rcs

INC			=		-I ./includes

all: 		$(OBJS) $(NAME)

%.o:		%.c
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
					@echo "Compiling OK!"

$(NAME):	$(OBJS)
					@echo "Creating executable"
					@$(LIBC) $(NAME) $(OBJS)
					@echo "Job's done!"

clean:
					@echo "Cleaning objects..."
					@rm -f $(OBJS)
					@echo "Cleaned up!"

fclean:		clean
					@echo "Cleaning..."
					@rm -f $(NAME)
					@echo "Cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re