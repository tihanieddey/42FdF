# Variables
CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIC

SRCS = \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_putendl_fd.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_toupper.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "Create	$(NAME)	: OK!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus