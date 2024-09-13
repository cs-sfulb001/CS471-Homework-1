
CXX = g++
CXXFlags = -pthread -unistd 

SRC = src/main.cpp
target = my_program.sh

all: Question2

Question2:
	gcc src/Question2.c $(CXXFlags) -o Question2.out
Question3:
	gcc src/Question3.c $(CXXFlags) -o Question3.out

clean:
	rm -f *.out