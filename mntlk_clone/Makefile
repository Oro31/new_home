CFLAGS = -Wall -Wextra -Werror -std=c11 -D_XOPEN_SOURCE=600 -D_POSIX_CSOURCE=200112L

NAME = serveur

NAMEC = client

SRCS =	src/serveur.c	\
		src/serveur_utils.c	\
		src/utils.c	\

SRCC = src/client.c	\
	   src/serveur_utils.c	\
	   src/utils.c	\

OBJS =	$(SRCS:%.c=%.o)

OBJC = $(SRCC:%.c=%.o)

all: $(NAME) $(NAMEC)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

$(NAMEC): $(OBJC)
	gcc -o $(NAMEC) $(OBJC)

clean:
	rm -f $(OBJS) $(OBJC)

fclean: clean
	rm -f $(NAME) $(NAMEC)

re: fclean all

.PHONY: clean fclean all re
