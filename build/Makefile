.PHONY: clean version

SRC_PATH = ../src
INC_PATH = ../include
CXX = g++ # Remove if you haven't g++ 10 or use another compiler by default
CXXFLAGS = -std=c++17 -I../include -Wall -Wextra -pthread -O2
OBJ = home.o cats.o player.o main.o 

all: cats

cats: ${OBJ}
	$(CXX) ${CXXFLAGS} -o cats ${OBJ}
	
cats.o: ${INC_PATH}/cats.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/cats.cpp
	
home.o: ${INC_PATH}/home.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/home.cpp
	
player.o: ${INC_PATH}/player.hpp
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/player.cpp
	
main.o:
	$(CXX) ${CXXFLAGS} -c ${SRC_PATH}/main.cpp

clean:
	@rm -r *.o cats

version:
	$(CXX) --version
