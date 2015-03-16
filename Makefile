PROJECT = gtk-demo

all:
	mkdir -p bin
	gcc src/$(PROJECT).c -o bin/$(PROJECT) `pkg-config --cflags --libs gtk+-2.0`

clean:
	rm -f bin/$(PROJECT)
