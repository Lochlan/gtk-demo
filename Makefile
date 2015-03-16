PROJECT = gtk-demo

CC = gcc
CFLAGS = $(shell pkg-config --cflags --libs gtk+-2.0)

SRCDIR = src
BUILDDIR = bin
OBJS = $(patsubst \
	%.c,\
	%.o,\
	$(shell find $(SRCDIR) -type f -name '*.c'))
MAKEDEPS = $(OBJS:.o=.d)
PROG = $(BUILDDIR)/$(PROJECT)

# targets

all: $(PROG)

clean:
	$(RM) $(PROG)
	$(RM) $(OBJS)
	$(RM) $(MAKEDEPS)

run: all
	./$(PROG)

# file rules

%.d: %.c
	$(CC) -M $< -MT "$(<:.c=.o) $@" $(CFLAGS) -o $@

$(PROG): $(OBJS)
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(CFLAGS)

# note: using implicit rule for .o object files

# autodependencies
ifneq ($(MAKECMDGOALS),clean)
include $(MAKEDEPS)
endif
