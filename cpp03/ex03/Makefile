CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = main 
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

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