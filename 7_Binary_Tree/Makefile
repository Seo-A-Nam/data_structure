SRCS =	srcs/bintree.c srcs/bintree_traverse.c srcs/main.c srcs/linkeddeque.c

INCS =	includes/

NAME =	a.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCS)


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: all clean fclean re