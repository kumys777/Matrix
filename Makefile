OPTS = -O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: a.out

a.out: a.o matrix.o
	g++ a.o matrix.o -o a.out

a.o: main.cpp matrix.h 
	g++ $(OPTS) -c main.cpp -o a.o

matrix.o: matrix.cpp matrix.h exception.h
	g++ $(OPTS) -c matrix.cpp -o matrix.o

clean:
	rm -f *.o *.out
