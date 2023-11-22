# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:52:56 by ade-beco          #+#    #+#              #
#    Updated: 2023/11/22 23:36:44 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

SRCS 		=		src/ft_printf.c src/ft_base.c src/ft_treatments.c src/ft_utils.c

OBJS		=		$(SRCS:.c=.o)

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