SRCS = phonebook.cpp Contact.cpp main.cpp
HEADERS = PhoneBook.hpp Contact.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = clang++
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
