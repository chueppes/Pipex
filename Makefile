NAME	= pipex.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
RM	= /bin/rm -f
RANLIB = ranlib
FILE    = pipex
LIBRARY = ./libft/

SRC	= ft_path.c ft_error.c pipex.c 

OBJS	= $(SRC:.c=.o)

.c.o:	
	$(CC) $(CFLAGS) -I $(LIBRARY) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	cd $(LIBRARY) && $(MAKE) && cp -v libft.a ../$(NAME)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	$(CC) $(NAME) -o $(FILE)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(FILE)
	cd $(LIBRARY) && $(MAKE) clean

fclean:	clean
	$(RM) $(NAME) 
	cd $(LIBRARY) && $(MAKE) fclean

re:	fclean all

.PHONY: all clean fclean re

