CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = main
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)

re: fclean all