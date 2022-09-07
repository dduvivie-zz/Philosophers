NAME		= philosophers

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c \
			check_args.c \
			init_structs.c \
			start.c \
			philo_actions.c \
			libft_functions.c \


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
