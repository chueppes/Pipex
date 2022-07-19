NAME	= pipex
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= /bin/rm -f
RANLIB = ranlib
LIBRARY = ./libft/

SRC	= ft_path.c ft_error.c pipex.c 

OBJS	= $(SRC:.c=.o)

.c.o:	
	$(CC) $(CFLAGS) -I $(LIBRARY) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBRARY) 
	$(CC) $(OBJS) $(LIBRARY)libft.a -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(FILE)
	$(MAKE) -C $(LIBRARY) clean

fclean:	clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBRARY) fclean

re:	fclean all

.PHONY: all clean fclean re

