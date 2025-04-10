# NAME = simple_calc
# TEST_NAME = test_simple_calc
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g



# SRCS_DIR = srcs
# OBJS_DIR = objs

# SRCS = evaluate.c \
# 		main_simple_calc.c \
# 		parser_functions.c \
# 		parser.c \
# 		tokenizer.c

# OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# TEST_SRCS = $(filter-out main_simple_calc.c, $(SRCS)) \
# 			test_main_simple_calc.c

# TEST_OBJS = $(TEST_SRCS:%.c=$(OBJS_DIR)/%.o)

# all: $(NAME)

# test: $(TEST_NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# $(TEST_NAME): $(TEST_OBJS)
# 	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
# 	@mkdir -p $(OBJS_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJS_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


NAME = simple_calc
TEST_NAME = test_simple_calc
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = evaluate.c \
        main_simple_calc.c \
        parser_functions.c \
        parser.c \
        tokenizer.c

# Test sources exclude main_simple_calc.c and include test_main_simple_calc.c
TEST_SRCS = $(filter-out main_simple_calc.c, $(SRCS)) \
            test_main_simple_calc.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

test: $(TEST_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re