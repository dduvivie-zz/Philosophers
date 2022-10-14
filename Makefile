# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 19:09:48 by dduvivie          #+#    #+#              #
#    Updated: 2022/10/12 19:09:51 by dduvivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c \
			check_args.c \
			init_structs.c \
			init_structs2.c \
			start.c \
			philo_eat.c \
			philo_state.c \
			philo_actions.c \
			libft_functions.c \
			timer.c	\
			exit.c


OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ) -lpthread

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
