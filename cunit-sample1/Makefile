# Makefile

CXXFLAGS += -Wall -g
CXXFLAGS += -I./src

LDFLAGS += -Wl,--as-needed
LIBS += -lpthread
LIBS += -lcunit

SRCS += src/sample1.cpp \
		tst/sample1_cunit.cpp
OBJS = $(SRCS:.cpp=.o)

TST = sample1_cunit

.SUFFIXES: .cpp
.PHONY: all $(TST)

all: $(TST)

$(TST): $(OBJS)
	@echo link: $?
	@echo       $@
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS) 

.cpp.o:
	@echo compling : $?
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TST) $(OBJS) *.orig

help:
	@echo On Ubuntu-12.04, installing the package:
	@echo $$ sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

