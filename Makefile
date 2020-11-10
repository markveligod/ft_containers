NAME = start
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ./main.cpp ./tests/list_test.cpp ./tests/vector_test.cpp
OBJ=$(SRC:.cpp=.o)
DEBUG = -g
LOG = log_*

#colors
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
CYAN=\033[1;36m
RESET=\033[0m

%.o:%.cpp
	@clang++ $(DEBUG) -o $@ -c $< $(FLAGS)
	@echo "[$(GREEN)OK$(RESET)]$(YELLOW) Compiling $<$(RESET)"

$(NAME): $(OBJ)
	@clang++ -o $(NAME) $(DEBUG) $(OBJ) $(FLAGS)
	@echo "[$(GREEN)Success$(RESET)]$(GREEN) Successfully compiled $(NAME) project.$(RESET)"
	@echo ""
	@echo "$(CYAN)      /|/|"
	@echo "     ( @ @)"
	@echo "      ) ^ $(RESET)   ft_containers (project 2020) $(CYAN)"
	@echo "     / |||       $(RESET) by ckakuna$(CYAN)"
	@echo "    / )|||_"
	@echo "   (_______)$(RESET)"
	@echo ""
	@echo "$(RED)[For example]:$(RESET)"
	@echo "$(YELLOW)./$(NAME) $(RESET)"
	@echo ""

all: $(NAME)

clean:
	@rm $(OBJ)
	@echo "[$(RED)Deleting$(RESET)]$(RED) Object files deleted.$(RESET)"

fclean: clean
	@rm $(NAME)
	@rm $(LOG)
	@echo "[$(RED)Deleting$(RESET)]$(RED) $(NAME) deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re