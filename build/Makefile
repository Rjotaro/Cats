.PHONY: clean version

SRC_PATH = ../src
INC_PATH = ../include
CXX = g++-10 # Remove if you haven't g++ 10 or use another compiler by default
CXXFLAGS = -std=c++2a -I../include -Wall -Wextra -Werror -pthread -O2

all: cats

cats: home.o cats.o player.o main.o
	$(CXX) ${CXXFLAGS} -o cats *.o
cats.o: ${INC_PATH}/cats.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/cats.cpp
home.o: ${INC_PATH}/home.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/home.cpp
player.o: ${INC_PATH}/player.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/player.cpp
main.o: ${INC_PATH}
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/main.cpp

clean:
	@rm -r *.o cats

version:
	$(CXX) --version
