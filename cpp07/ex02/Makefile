# **************************************************************************** #
#                                                                              #
#    Host: e4r2p4.42roma.it                                           /_/      #
#    File: Makefile                                                ( o.o )     #
#    Created: 2025/06/13 13:24:11 | By: atucci <atucci@student.42  > ^ <       #
#    Updated: 2025/06/18 15:05:23                                   /          #
#    OS: Linux 6.5.0-44-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)      #
#                                                                              #
# **************************************************************************** #

NAME = array
SOURCE = main.cpp \

FLAG = -Wall -Werror -Wextra -std=c++98
CXX = c++
OBJ = $(SOURCE:.cpp=.o)

# **************************************************************************** #
# Color codes for echo commands to make the output more visually informative.  #
# **************************************************************************** #
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m


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
