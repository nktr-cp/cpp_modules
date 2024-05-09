NAME := ex02
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

check: all
	leaks -q -atExit -- ./$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
