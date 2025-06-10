SRCS = main.cpp Zombie.cpp
HEADERS = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = Zombies
CXXFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=leak,address -std=c++98
CXX = c++
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)  # Ensure headers are dependencies
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
