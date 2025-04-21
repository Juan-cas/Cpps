SRCS = Bureaucrat.cpp Form.cpp main.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp test_batch_1.cpp test_batch_2.cpp test_batch_3.cpp
HEADERS = Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp tests.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = Office
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
