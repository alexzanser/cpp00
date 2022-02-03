NAME = phonebook
SOURCE = phonebook.cpp
CFLAGS = -Wall -Werror -Wextra -I $(HEADER)
HEADER = phonebook.hpp
CC = c++
OBJ = $(SOURCE:%.cpp=%.o)
.PHONY : all clean fclean re
#
all : $(NAME)
#
$(NAME) :	$(SOURCE) ${HEADER}
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)
#
%.o :	%.c ${HEADER}
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
#
fclean : clean
	@rm -f $(NAME)
#
re : fclean all
