CC = c++
CFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -Wshadow -g -std=c++98
NAME = main 
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Serializer.hpp

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