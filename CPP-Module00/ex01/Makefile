#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = ftBook
.DEFAULT_GOAL := all
.PHONY: all clean fclean re help
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
INCLUDES_DIR := includes/

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

# SRCS := $(wildcard $(SRC_DIR)*.cpp)
SRCS =	$(addprefix $(SRCS_DIR),\
		Contact.cpp \
		Main.cpp \
		PhoneBook.cpp)
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)
INCLUDES = $(wildcard $(INCLUDES_DIR)*.hpp)

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = c++

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
DFLAGS = -g3 -Wall -Wextra -Werror -std=c++98
COMP_OBJ = $(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
COMP_EXE = $(CC) $(OBJS) -o $(NAME)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	@if [ $(COUNT) -eq 1 ]; then \
		printf "$(YELLOW)Building ftBook files\n$(RESET)"; \
	fi
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling ftBook$(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
	@if [ $(COUNT) -eq $(words $(SRCS)) ]; then \
		printf " Compiled $(DARK_GREEN)ftBook 100%%$(FCOLOR) ✅"; \
	fi
endef

define comp_exe
	$(COMP_EXE)
	printf "\n \n"
	printf "$(DARK_BLUE)ftBook $(RESET)$(PURPLE)is Ready\n$(RESET)"
endef

define help
	echo "${DARK_RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}all:${RESET} ${LIGHT_GRAY}Build a ftBook${RESET}"
	echo "${DARK_BLUE}re:${RESET} ${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}clean:${RESET} ${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET} ${LIGHT_GRAY}Remove the program and the object files${RESET}"
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

-include $(DEPS)
