SRCS = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
HEADERS = AMaria.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = Final_Fantasy
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
