SRCS	= 

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

CC		= gcc -g -fsanitize=address -Wall -Wextra -Werror *.c -lmlx -framework OpenGL -framework AppKit

NAME	= so_long.a

all: $(NAME)

%.o: %.c
		gcc -g -Werror -Wextra -Wall -c $<

$(NAME): $(OBJS)
	@$(CC)

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

bonus:
	@make SRCS="$(SRCS) $(SRCS_B)"

.PHONY: all clean fclean re bonus