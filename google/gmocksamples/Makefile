# Makefile

E_RED = \e[1;31m
E_GREEN = \e[1;32m
E_YELLOW = \e[1;33m
E_END = \e[0m

CXXFLAGS += -Wall -g
CXXFLAGS += -I.
CXXFLAGS += -I$(DIR_GTEST)/include
CXXFLAGS += -I$(DIR_GMOCK)/include

LDFLAGS += -Wl,--as-needed
LIBS += -lpthread
LIBS += -L$(DIR_GTEST)/lib/.libs -lgtest_main -lgtest
LIBS += -L$(DIR_GMOCK)/lib/.libs -lgmock_main -lgmock

SRCS_1 += gmock-ex-test.cc
OBJS_1 = $(SRCS_1:.cc=.o)
APP_1 = gmock-ex-test

SRCS_2 += gmock-leak-test.cc
OBJS_2 = $(SRCS_2:.cc=.o)
APP_2 = gmock-leak-test

SRCS_3 += gmock-link-test.cc
OBJS_3 = $(SRCS_3:.cc=.o)
APP_3 = gmock-link-test

SRCS_4 += gmock-output-test.cc
OBJS_4 = $(SRCS_4:.cc=.o)
APP_4 = gmock-output-test

# gmock-generated-function-mockers-test.cc

.SUFFIXES: .cc
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

all: $(APP_1) \
	$(APP_2) \
	$(APP_3) \
	$(APP_4)

$(APP_1): $(OBJS_1)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

$(APP_2): $(OBJS_2)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

$(APP_3): $(OBJS_3)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

$(APP_4): $(OBJS_4)
	@echo -e "link: $(E_YELLOW)$?$(E_END)"
	@echo -e "      $(E_YELLOW)$@$(E_END)"
	@$(CXX) $(LDFLAGS) -o $@ $? $(LIBS)

clean:
	$(RM) $(APP_1) $(OBJS_1) *.orig
	$(RM) $(APP_2) $(OBJS_2) *.orig
	$(RM) $(APP_3) $(OBJS_3) *.orig
	$(RM) $(APP_4) $(OBJS_4) *.orig

help:
	@echo $$ sudo ldconfig $DIR_GMOCK/lib/.libs  $DIR_GTEST/lib/.libs

#
#  Now list the dependencies.
#  This is the "modern" equivalent of the old "makedepend" command that avoids us having to specify the header files explicitly.
#  We have one dependency file for each source file
#
-include $(SRCS_1:.cc=.d) $(SRCS_2:.cc=.d) $(SRCS_3:.cc=.d) $(SRCS_4:.cc=.d)
