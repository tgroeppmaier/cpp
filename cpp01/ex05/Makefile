CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = main
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = Harl.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(HDRS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all