CC = c++
CFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -Wshadow -g -std=c++98
NAME = main 
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Base.hpp A.hpp B.hpp C.hpp

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