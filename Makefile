all:
	clang++ -g -fsanitize=address -Wall -Wextra -Werror main_test.cpp