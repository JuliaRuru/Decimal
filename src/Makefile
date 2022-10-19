OS := $(shell uname -s)
CC = gcc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
FLAGS = -lcheck -lm
CFLAGS = -Wall -Wextra -Werror -std=c11
OBJECTS = decimal.o comparison.o other_functions.o helpers.o

all: clean test

decimal.a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

decimal.o: decimal.c decimal.h comparison.c other_functions.c helpers.c
	$(CC) $(CFLAGS) -c -o $@ $<

test.o: tests.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: test.o decimal.a
	$(CC) $(CFLAGS) $^ $(FLAGS) -o $@
	./$@

gcov_report:
	$(CC) --coverage tests.c -o test decimal.c helpers.c comparison.c other_functions.c $(FLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check: test
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	python3 ../materials/linters/cpplint.py --extensions=c *.h
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind --leak-check=full --show-leak-kinds=all ./test
endif
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidPointerCast --suppress=shiftTooManyBitsSigned *.c *.h

clean:
	rm -f *.o test *.a
	rm -rf *.gcno *.gcda test *.info
	rm -rf report
	rm -rf *.cfg
