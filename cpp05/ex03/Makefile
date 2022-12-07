NAME = bureaucrat
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

YELLOW ="\033[0;33m"
RESET = "\033[0m"

BUILD_DIR = build

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo file: $(YELLOW)$(NAME)$(RESET) has created

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
