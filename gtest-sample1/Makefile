# Makefile

CXXFLAGS += -Wall -g
CXXFLAGS += -I./src

LDFLAGS += -Wl,--as-needed
LIBS += -lpthread
LIBS += -L/usr/lib -lgtest_main -lgtest 

SRCS += src/sample1.cpp \
		tst/sample1_unittest.cpp
OBJS = $(SRCS:.cpp=.o)

TST = sample1_unittest

.SUFFIXES: .cpp
.PHONY: all $(TST)

all: $(TST)

$(TST): $(OBJS)
	@echo link: $?
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS) 

.cpp.o:
	@echo compling : $?
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TST) $(OBJS) *.orig

help:
	@echo On Ubuntu-12.04, installing and building the gtest package:
	@echo $$ sudo apt-get install libgtest-dev
	@echo /usr/src/gtest $$ sudo cmake CMakeLists.txt
	@echo /usr/src/gtest $$ sudo make
	@echo /usr/src/gtest $$ sudo cp -va *.a /usr/lib
