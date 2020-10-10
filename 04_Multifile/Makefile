GENERATES = prog *.so prog-so prog-a
TRASH = *.o *~ o.* *.a  *err.txt *out.txt
CFLAGS = -Wall -fPIC
TEST_PARAMS1 = abc
TEST_PARAMS3 = 12 34 56

all:    README prog

prog:   const.o fun.o prog.o

liboutput.so: const.o fun.o
	cc -shared $^ -o $@

liboutput_static.a: const.o fun.o
	ar -rcs $@ $^

prog-so: prog.o liboutput.so
	cc -L. $< -loutput -o $@

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@

test: prog-so prog-a prog
	for BINFILE in $^ ; do \
		LD_LIBRARY_PATH=`pwd` ./$${BINFILE} 1>$${BINFILE}_0_out.txt 2>$${BINFILE}_0_err.txt; \
	done
	for BINFILE in $^ ; do \
		LD_LIBRARY_PATH=`pwd` ./$${BINFILE} $(TEST_PARAMS1) 1>$${BINFILE}_1_out.txt; \
	done
	for BINFILE in $^ ; do \
		LD_LIBRARY_PATH=`pwd` ./$${BINFILE} $(TEST_PARAMS3) 1>$${BINFILE}_3_out.txt; \
	done
	for SUFF in 0 1 3; do \
		for BINFILE1 in $^ ; do \
			for BINFILE2 in $^ ; do \
				cmp $${BINFILE1}_$${SUFF}_out.txt $${BINFILE2}_$${SUFF}_out.txt; \
			done \
		done \
	done
fun.o: outlib.h

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
