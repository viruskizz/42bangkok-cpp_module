NAME = phonebook
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

BUILD_DIR = build

SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
