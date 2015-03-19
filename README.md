# gtk-demo

Just messing around with GTK+ 2.

Right now this is basically just the hello world program from the [GTK+ 2.0 Tutorial](https://developer.gnome.org/gtk-tutorial/stable/book1.html), although I'm slowly adding widgets to it and evolving it as a program, to eventually turn it into something else.

# Build

## Linux (Debian/Ubuntu)

```bash
# install dependencies
sudo apt-get install gtk+-2.0

# build
make
```

## Mac

You'll need XCode and [homebrew](http://brew.sh/) to get started.

```bash
# install dependencies
brew install pkg-config # used by makefile
brew install Caskroom/cask/xquartz # used by GTK
brew install gtk+

# make sure that cairo can find xcb-shm
echo "export PKG_CONFIG_PATH=/usr/X11/lib/pkgconfig" >> ~/.bash_profile

# build
make
```

Note that you will only be able to run the application from X11/XQuartz.  Executing the binary from a non-X11 shell will require the `DISPLAY` environment variable.  To get the correct value open the X11 terminal and run the following command:

```bash
echo "export DISPLAY=$DISPLAY" >> ~/.bash_profile
```

Set the `PKG_CONFIG_PATH` environment variable to enable building (but not running) using the login shell
