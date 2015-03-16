PROJECT = gtk-demo

CC = gcc
CFLAGS = $(shell pkg-config --cflags --libs gtk+-2.0)

SRCDIR = src
BUILDDIR = bin

all: $(BUILDDIR)/$(PROJECT)

clean:
	rm -f $(BUILDDIR)/$(PROJECT)

run: all
	./$(BUILDDIR)/$(PROJECT)

# file rules

$(BUILDDIR)/%: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) -o $@ $< $(CFLAGS)
