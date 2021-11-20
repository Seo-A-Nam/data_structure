SRCS	=	main.c \
			arraylist.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFALGS = -Wall -Werror -Wextra

NAME = main

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFALGS) -o $(NAME) $(OBJS)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)
			
re			:	fclean $(NAME)

.PHONY		:	all clean fclean re