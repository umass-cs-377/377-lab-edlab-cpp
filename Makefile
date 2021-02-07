.PHONY : all
all : map set queue

.DEFAULT_GOAL := all

clean:
	rm map set queue

map: map.cpp
	g++ -o map map.cpp

set: set.cpp
	g++ -o set set.cpp

queue: queue.cpp
	g++ -o queue queue.cpp
