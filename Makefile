CC=clang
CFLAGS=-g -Wall

SRC=src
OBJ=obj
INC=include
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o, $(SRCS))
TESTS=test/main.c

BINDIR=bin
SO=$(BINDIR)/libdsa.so
TESTBIN=$(BINDIR)/test

all: $(SO)

test: $(TESTBIN)
	LD_LIBRARY_PATH=$(BINDIR) ./$(TESTBIN)

$(SO): $(OBJS)
	$(CC) $(CFLAGS) -fPIC -shared $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c -I $(INC) $< -o $@

$(TESTBIN): $(SO) $(TESTS)
	$(CC) $(CFLAGS) -o $@ -I $(INC) $(TESTS) $<

format:
	clang-format -i src/* include/*
clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*
