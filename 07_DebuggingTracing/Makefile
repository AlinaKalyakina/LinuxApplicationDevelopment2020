
GENERATES = wrapper.so testfile testFIXfile
TRASH = *.o *~ o.*

all: lib test

lib:
	gcc -g -fPIC -shared  wrapper.c -o wrapper.so -ldl

test:
	touch testfile
	rm testfile
	@if [ -f testfile ]; then echo "Error"; else echo "Ok";	fi;
	touch testfile
	LD_PRELOAD="./wrapper.so" rm testfile
	@if [ -f testfile ]; then echo "Error"; else echo "Ok"; fi;
	touch testFIXfile
	rm testFIXfile
	@if [ -f testFIXfile ]; then echo "Error"; else echo "Ok"; fi;
	touch testFIXfile
	-LD_PRELOAD="./wrapper.so" rm testFIXfile
	@if [ -f testFIXfile ]; then echo "Ok"; else echo "Error"; fi;

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)
