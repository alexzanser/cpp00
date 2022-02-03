NAME = megaphone
SOURCE = megaphone.cpp
CFLAGS = -Wall -Werror -Wextra
CC = c++
OBJ = $(SOURCE:%.cpp=%.o)
.PHONY : all clean fclean re
#
all : $(NAME)
#
$(NAME) :	$(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)
#
%.o :	%.c
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
#
fclean : clean
	@rm -f $(NAME)
#
re : fclean all
