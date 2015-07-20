# Makefile

E_RED = \e[1;31m
E_GREEN = \e[1;32m
E_YELLOW = \e[1;33m
E_END = \e[0m

CXXFLAGS += -Wall -g
CXXFLAGS += -I./src
CXXFLAGS += -I./tst
CXXFLAGS += -I$(DIR_GTEST)/include
CXXFLAGS += -I$(DIR_GMOCK)/include

LDFLAGS += -Wl,--as-needed
LIBS += -lpthread
LIBS += -L$(DIR_GTEST)/lib/.libs -lgtest_main -lgtest
LIBS += -L$(DIR_GMOCK)/lib/.libs -lgmock_main -lgmock

SRCS += \
		tst/mock_turtle_test.cpp
OBJS = $(SRCS:.cpp=.o)

TST = sample1_gmock

.SUFFIXES: .cpp
.PHONY: all

%.o: %.c
	@echo -e "compiling : $(E_GREEN)$?$(E_END)"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o: %.cpp
	@echo -e "compiling : $(E_GREEN)$?$(E_END)"
	@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

%.o: %.cc
	@echo -e "compiling : $(E_GREEN)$?$(E_END)"
	@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

all: $(TST)

$(TST): $(OBJS)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

clean:
	$(RM) $(TST) $(OBJS) *.orig

help:
	@echo $$ sudo ldconfig $DIR_GMOCK/lib/.libs  $DIR_GTEST/lib/.libs

