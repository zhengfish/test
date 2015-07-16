# Makefile

E_RED = \e[1;31m
E_GREEN = \e[1;32m
E_YELLOW = \e[1;33m
E_END = \e[0m

CXXFLAGS += -Wall -g
CXXFLAGS += -I./src

LDFLAGS += -Wl,--as-needed
LIBS += -lpthread
LIBS += -lgtest_main -lgtest

SRCS += src/sample1.cpp \
		tst/sample1_gtest.cpp
OBJS = $(SRCS:.cpp=.o)

TST = sample1_gtest

.SUFFIXES: .cpp
.PHONY: all

all: $(TST)

$(TST): $(OBJS)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

.cpp.o:
	@echo -e "compiling : $(E_GREEN)$?$(E_END)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TST) $(OBJS) *.orig

help:
	@echo On Ubuntu-12.04, installing and building the gtest package:
	@echo $$ sudo apt-get install libgtest-dev
	@echo /usr/src/gtest $$ sudo cmake CMakeLists.txt
	@echo /usr/src/gtest $$ sudo make
	@echo /usr/src/gtest $$ sudo cp -va *.a /usr/lib

