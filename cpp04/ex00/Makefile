CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -g -std=c++98
NAME = main 
SRC = main.cpp Animal.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Animal.hpp

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