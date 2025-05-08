# Source and output files
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
	@printf "\n"
	@printf "$(GREEN)"
	@printf "   ____ ____  ____    __  __           _       _         ___   ___  \n"
	@printf "  / ___|  _ \\|  _ \\  |  \\/  | ___   __| |_   _| | ___   / _ \\ / _ \\ \n"
	@printf " | |   | |_) | |_) | | |\\/| |/ _ \\ / _\` | | | | |/ _ \\ | | | | | | |\n"
	@printf " | |___|  __/|  __/  | |  | | (_) | (_| | |_| | |  __/ | |_| | |_| |\n"
	@printf "  \\____|_|   |_|     |_|  |_|\\___/ \\__,_|\\__,_|_|\\___|  \\___/ \\___/ \n"
	@printf "$(RESET)\n"

# Linking the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove executable and object files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Don't treat these targets as files
.PHONY: all clean fclean re