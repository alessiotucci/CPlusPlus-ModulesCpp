# **************************************************************************** #
#                                                                              #
#    Host: e4r2p4.42roma.it                                           /_/      #
#    File: Makefile                                                ( o.o )     #
#    Created: 2025/06/13 13:23:57 | By: atucci <atucci@student.42  > ^ <       #
#    Updated: 2025/06/18 11:17:26                                   /          #
#    OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)      #
#                                                                              #
# **************************************************************************** #

# *********************************
# setting up the name of the exec *
# *********************************
NAME = iter

# *************************************************
# setting up the variable that will be the source *
# *************************************************
SOURCE = main.cpp \
		 Profile.cpp \


# ***********************************************************
# setting up the flag that will be used for the compilation *
# ***********************************************************
FLAG = -Wall -Wextra -Werror -std=c++98


# ***************************************************************
# setting up the compiler that will be used for the compilation *
# ***************************************************************
CXX = c++


# ***************************************************************
# using the implicit rules of makefile, we will create the objs *
# it is called "substitution reference"                         *
# ***************************************************************
OBJ = $(SOURCE:.cpp=.o)

# **************************************************************************** #
# Color codes for echo commands to make the output more visually informative.  #
# **************************************************************************** #
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m

# ****************
# Default target *
# ****************
all: $(NAME)

# *******************************
# Rule for building the program *
# *******************************
$(NAME): $(OBJ)
	@echo "$(GREEN)Linking...$(RESET)\n"
	$(CXX) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Done!\n$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CXX) $(FLAG) -c $< -o $@
	@echo "$(CYAN)Done compiling $<.$(RESET)\n"


# ****************************************
#  Rule for cleaning up the object files *
# ****************************************
clean:
	@echo "$(YELLOW)Cleaning up object files...$(RESET)"
	rm -f $(OBJ)
	@echo "$(YELLOW)Done!\n$(RESET)"

# *******************************************************
# Rule for cleaning up the object files and the program *
# *******************************************************
fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	rm -f $(NAME)
	@echo "$(RED)Done!\n$(RESET)"

# **********************************
# Rule for recompiling the program *
# **********************************
re: fclean all

#--------------------------------------------------
# .PHONY targets to specify non-file targets      *
#--------------------------------------------------
.PHONY: all clean fclean re


#--------------------------------------------------
# Rule for deleting the hidden files generated
hidden:
	@echo "$(YELLOW) Listing hidden files:"
	@find . \( -name ".DS_Store" -o -name ".*.swp" -o -name ".*.swo" -o -name "a.out" \) -type f -print
	@echo "$(RESET)$(RED) Deleting hidden files: $(RESET)"
	@find . \( -name ".DS_Store" -o -name ".*.swp" -o -name ".*.swo" -o -name "a.out" \) -type f -delete
