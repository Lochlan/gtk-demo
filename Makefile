PROJECT = gtk-demo

all:
	gcc $(PROJECT).c -o $(PROJECT) `pkg-config --cflags --libs gtk+-2.0`

clean:
	rm -f $(PROJECT)
