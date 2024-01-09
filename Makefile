# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 16:52:56 by ade-beco          #+#    #+#              #
#    Updated: 2024/01/09 18:00:08 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF		=		libftprintf

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRCS 		=		ft_printf.c ft_printf_base.c ft_printf_utils.c

OBJECTS		=		$(SRCS:.c=.o)

CC			=		cc -Wall -Wextra -Werror -g

LIBC		=		ar rcs

INC			=		-I ./ft_printf.h $(LIBFT_PATH)$(LIBFT).h

all: 		$(PRINTF)

$(PRINTF): $(OBJECTS) $(LIBFT_PATH)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@echo "OK !"
					@cp $(LIBFT_PATH)$(LIBFT).a $(PRINTF).a
					@echo "Creating PRINTF Executable..."
					@ar -rcs $(PRINTF).a $(OBJECTS)
					@echo "OK !"

$(OBJECTS): $(SRCS)
					@echo "Compiling PRINTF..."
					@clang -Wall -Wextra -Werror -c $(SRCS)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning objects..."
					@rm -f $(OBJECTS)
					@echo "Cleaned up!"

fclean:		clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning..."
					@rm -f $(PRINTF).a
					@echo "Cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re