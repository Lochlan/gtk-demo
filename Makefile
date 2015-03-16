PROJECT = gtk-demo

CC = gcc
CFLAGS = $(shell pkg-config --cflags --libs gtk+-2.0)

SRCDIR = src
BUILDDIR = bin
OBJS = $(patsubst \
	%.c,\
	%.o,\
	$(shell find $(SRCDIR) -type f -name '*.c'))
PROG = $(BUILDDIR)/$(PROJECT)

# targets

all: $(PROG)

clean:
	$(RM) $(PROG)
	$(RM) $(OBJS)

run: all
	./$(PROG)

# file rules

$(PROG): $(OBJS)
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(CFLAGS)

# note: using implicit rule for .o object files
