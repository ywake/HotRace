#############
# Variables #
#############

NAME	:= hotrace
CC		:= cc
INCLUDE	:= -I./includes
CFLAGS	:= -O3 -g -Wall -Werror -Wextra $(INCLUDE)
LIBS	:=
VPATH	:= srcs/

ifeq ($(shell uname), Linux)
	CFLAGS += -Wno-unused-result
endif

SRCS	:= main.c \
			avl/avl_get.c avl/avl_insert.c avl/avl_rebalance.c avl/avl_rotations.c avl/avl_utils.c \
			io/read_stdin.c io/file_to_lines.c io/buffering.c \
			utils/free_set.c utils/ft_lite_split.c utils/ft_putstr_fd.c utils/ft_strcmp.c utils/ft_strjoin.c utils/ft_strlen.c \
			utils/ft_lst_reverse.c utils/ft_lstadd_front.c utils/ft_lstclear.c utils/ft_lstdelone.c utils/ft_lstnew.c

OBJDIR	:= objs/
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

DSTRCTR	:= ./tests/destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean: FORCE
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	$(RM) -r $(NAME).dSYM $(B_NAME).dSYM

re: fclean all

norm: FORCE
	@printf "$(RED)"; norminette | grep -v ": OK!" \
	&& exit 1 \
	|| printf "$(GREEN)%s\n$(END)" "Norm OK!"

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)$(*D)
	@printf "$(THIN)$(ITALIC)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(END)"

.PHONY: FORCE
FORCE:

###############
# Debug rules #
###############

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

sani: $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

Darwin_leak: $(DSTRCTR) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: sani

leak: $(shell uname)_leak

##############
# Test rules #
##############

CXX			:= clang++
CXXFLAG		:= -std=c++11 -g -fsanitize=address -Wno-writable-strings
gTestDir	:= ./.google_test
gVersion	:= release-1.11.0
gTestVer	:= googletest-$(gVersion)
gTest		:= $(gTestDir)/gtest $(gTestDir)/$(gTestVer)

TESTDIR		:= ./tests/
TESTSRCS_C	:= $(filter-out main.c,$(SRCS))
TESTSRCS_CPP:= $(wildcard $(TESTDIR)*.cpp)
TESTOBJS	:= $(addprefix $(OBJDIR), $(TESTSRCS_C:%.c=%.o)) \
				$(TESTSRCS_CPP:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAG) -I$(gTestDir) $(INCLUDE) -c $< -o $@

$(gTest):
	mkdir -p $(gTestDir)
	curl -OL https://github.com/google/googletest/archive/refs/tags/$(gVersion).tar.gz
	tar -xvzf $(gVersion).tar.gz $(gTestVer)
	$(RM) $(gVersion).tar.gz
	python $(gTestVer)/googletest/scripts/fuse_gtest_files.py $(gTestDir)
	mv $(gTestVer) $(gTestDir)

test: FORCE $(gTest) $(TESTOBJS)
	@$(CXX) $(CXXFLAG) \
		$(TESTOBJS) \
		$(gTestDir)/$(gTestVer)/googletest/src/gtest_main.cc \
		$(gTestDir)/gtest/gtest-all.cc \
		-I$(gTestDir) $(INCLUDE) $(LIBS) -lpthread -o test && ./test

test_clean: FORCE
	$(RM) $(TESTOBJS)

test_fclean: test_clean
	$(RM) -r tester tester.dSYM

test_re: test_fclean test

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
