
CXX = g++
CXXFlags = -pthread -unistd 

SRC = src/main.cpp
target = my_program.sh

all: main

$(target): $(SRC)
	$(CXX) -o $@ $^

main:
	gcc src/main.c $(CXXFlags)

clean:
	del $(target)