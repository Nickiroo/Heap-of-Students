main: main.cpp date.cpp address.cpp student.cpp
	g++ -std=c++17 -Wall -o main main.cpp date.cpp address.cpp student.cpp

clean:
	rm -f main

.PHONY: clean
