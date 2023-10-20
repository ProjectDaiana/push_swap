SOURCES	= main.c utils_minmax.c utils_checks.c utils_movements.c utils_list.c init_stack.c sort_three.c sort_five.c sort_radix.c libft/ft_atol.c libft/ft_isdigit.c libft/ft_calloc.c libft/ft_substr.c libft/ft_strlen.c libft/ft_strchr.c

NAME	= push_swap
OBJECTS = $(SOURCES:.c=.o) 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
${NAME}: ${OBJECTS}
		@${CC} ${OBJECTS} -o ${NAME} ${CFLAGS} 
all:	$(NAME)
clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm	-f $(NAME)
re:	fclean all
.PHONY: all clean fclean re