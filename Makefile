all: main

main: func.o
    g++ func.o -o main

func.o: func.cpp func.h
    g++ -c func.cpp

clean:
    rm -rf *.o main