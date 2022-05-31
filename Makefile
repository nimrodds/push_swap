SRCS			=	./srcs/push_swap.c \
					./srcs/special_case_one.c \
					./srcs/special_case_two.c \
					./srcs/utils_bits.c \
					./srcs/utils_lst.c \
					./srcs/utils_stack.c \
					./srcs/moves_one.c \
					./srcs/moves_two.c \
					./srcs/moves_three.c \
					./srcs/spliting.c 

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	./srcs/libftprintf.a

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -I./incs

NAME			= 	push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
