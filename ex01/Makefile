

# This sets the name of the final program file.
# CXX is the compiler (c++ is used to compile C++ files).
# CXXFLAGS are options:
# -Wall: show all warnings
# -Wextra: show extra warnings
# -Werror: treat warnings as errors

# Source and output files
SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Default rule
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
#  or better $(CXX) $(CXXFLAGS) -o $@ $^
#  where $@ expands to the target name ($(NAME)) $^ to all prerequisites ($(OBJ))
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
# -c

# Compile only (generate object file, don't link yet).
# $< Automatic variable refers to the first prerequisite (the .cpp file).
# Example: For main.o: main.cpp, $< = main.cpp.
# -o $@  - $@ Automatic variable refers to the target (the .o file).

Example: For main.o: main.cpp, $@ = main.o.
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