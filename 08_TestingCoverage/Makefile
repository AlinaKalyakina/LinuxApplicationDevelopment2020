TRASH = build/* test/*.c 
GENERATES = *.gcov *.gcda *.gcno 

SRC_DIR = src
TEST_C = test/test.c
BUILD_DIR = build
LIB = $(BUILD_DIR)/libbuf.so
TEST_EXE = $(BUILD_DIR)/test

CC = gcc
SHARED_FLAGS = -shared -fPIC
COVERAGE_FLAGS = --coverage -g -O0 -lgcov
TEST_FLAGS = `pkg-config --libs check` -L $(BUILD_DIR) -lbuf `pkg-config --cflags check`

all: profile

%.c : %.ts
	checkmk $< > $@

build_cov: $(SRC_DIR)/buf.c $(SRC_DIR)/buf.h
	$(CC) $< -o $(LIB) $(SHARED_FLAGS) $(COVERAGE_FLAGS)

build_test: $(SRC_DIR)/buf.c $(SRC_DIR)/buf.h
	$(CC) $< -o $(LIB) $(SHARED_FLAGS) 

profile: $(TEST_C) build_cov
	$(CC) $< -o $(TEST_EXE) $(TEST_FLAGS) -I $(SRC_DIR) 
	LD_LIBRARY_PATH=$(BUILD_DIR) ./$(TEST_EXE)

check: $(TEST_C)  build_test
	$(CC) $< -o $(TEST_EXE) $(TEST_FLAGS) -I $(SRC_DIR) 
	LD_LIBRARY_PATH=$(BUILD_DIR) ./$(TEST_EXE)

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)

.SUFFIXES:
.SUFFIXES: .ts .c
