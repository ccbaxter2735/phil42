NAME			= philo

CC				= cc 

FLAGS			= -Wall -Wextra -Werror -g

C_FILE		= main.c \
						philo_utils.c \
						philo_fct.c \
						philo_fct2.c \
						routine.c \
						dead.c \

SRC_DIR		=	./core/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

all : $(NAME)

$(NAME):  $(OBJ)
	@echo "\033[0;33m\nCOMPILING PHILOSOPHER...\n"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;33m./philo created\n"

clean:
	@echo "\033[1;32mDeleting philo object..."
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[1;32mDeleting philo executable..."
	@rm -f $(NAME)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re