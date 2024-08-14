#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = megaphone
.DEFAULT_GOAL := all
.PHONY: all clean fclean re help test run_test
.SILENT:

#! ******************************************************************************#
#                                   COLORS                                       #
#! ******************************************************************************#

DEFAULT=\033[39m
BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
RESET = \033[0m

#! ******************************************************************************#
#                                   PATH                                         #
#! ******************************************************************************#

SRC_DIR := src/
BUILD_DIR := build/
TESTS_DIR := test
TEST_BUILD_DIR := $(TESTS_DIR)/build
TEST_BIN_DIR := $(TESTS_DIR)/bin

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS := $(wildcard $(SRC_DIR)*.cpp)
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

TEST_SRCS := $(wildcard $(TESTS_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TESTS_DIR)/%.cpp, $(TEST_BUILD_DIR)/%.o, $(TEST_SRCS))
TEST_TARGET := $(TEST_BIN_DIR)/tests

GTEST_DIR := /usr/lib/gtest/googletest
GTEST_LIB := /usr/lib/gtest/lib/libgtest.a /usr/lib/gtest/lib/libgtest_main.a

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = c++
SHELL := /bin/bash

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS = -g3 -Wall -Wextra -Werror -Iinclude -isystem $(GTEST_DIR)/include
COMP_OBJ = $(CC) $(CFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(OBJS) -o $(NAME)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling Megaphone$(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_exe
	$(COMP_EXE)
	printf "\n"
	printf "$(GREEN)Megaphone $(RESET)->$(PURPLE) Is Ready\n$(RESET)"
endef

define help
	echo "${DARK_RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}all:${RESET} ${LIGHT_GRAY}Build a megaphone${RESET}"
	echo "${DARK_BLUE}re:${RESET} ${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}clean:${RESET} ${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET} ${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo "${DARK_BLUE}test:${RESET} ${LIGHT_GRAY}Compile tester length${RESET}"
endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.cpp
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

help:
	$(call help)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) | $(TEST_BIN_DIR)
	$(CXX) $(DFLAGS) -pthread -o $@ $(TEST_OBJS) $(GTEST_LIB)

$(TEST_BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp | $(TEST_BUILD_DIR)
	$(CC) $(DFLAGS) -c -o $@ $<

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

run_test: test
	@./$(TEST_TARGET)
	@rm -rf $(TEST_BIN_DIR) $(TEST_BUILD_DIR)

-include $(DEPS)
