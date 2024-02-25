NAME := ex03
SRC := main.cpp \
			 AMateria.cpp \
			 Cure.cpp \
			 Ice.cpp \
			 Character.cpp \
			 MateriaSource.cpp

OBJ := $(SRC:.cpp=.o)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

check: all
	leaks -q -atExit -- ./$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.c
	$(CCX) $(CCXFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
