GPP=g++
BIN=freaktal

OBJDIR=obj

LIBDIR= 
INCDIR=

CFLAGS=-std=c++11 -Wall -Wextra -Werror -pedantic -O2 -g

DEFINES=
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

CPPFILES=$(wildcard *.cpp) $(wildcard fragments/*.cpp)


OBJS=$(patsubst %.cpp,$(OBJDIR)/%.o,$(CPPFILES))

$(OBJDIR)/%.o : %.cpp
	$(GPP) $(CFLAGS) $(INCDIR) -c $< -o $@ $(DEFINES)

default: $(BIN)

$(BIN): $(OBJS)
	$(GPP) $(OBJS) -o $(BIN) $(LIBDIR) $(LIBS)

build:
	mkdir -p $(OBJDIR) $(OBJDIR)/fragments

clean:
	rm -f $(BIN) $(OBJS)

.PHONY: check
check:
	cppcheck -I. --inconclusive --enable=all .
