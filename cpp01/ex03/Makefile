SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = Fight_Club
CXXFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,leak -std=c++98
CXX = c++
RM = rm -f

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
