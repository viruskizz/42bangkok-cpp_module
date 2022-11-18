NAME = account
CXX = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

BUILD_DIR = build

SRCS = test.cpp \
		Account.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
