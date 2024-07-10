CC = c++
CFLAGS = -Wall -Wextra -Werror -Weffc++ -Wshadow -g -std=c++98
NAME = PmergeMe
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all