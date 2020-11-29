bin_PROGRAMS = main
AM_CFLAGS = $(GLIB_CFLAGS) -Wall
LIBS += $(GLIB_LIBS)

test: main
	./main < text.txt

gitclean:
	git clean -fd
