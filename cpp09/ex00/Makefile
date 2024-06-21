CC = c++
CFLAGS = -Wall -Wextra -Werror -Weffc++ -Wconversion -Wsign-conversion -Wshadow -g -std=c++98
NAME = btc
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = BitcoinExchange.hpp

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