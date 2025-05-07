SRCS = Animals.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS = Animals.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = Zoo
CXXFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,leak -std=c++98
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
