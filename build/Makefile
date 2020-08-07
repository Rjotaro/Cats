SRC_PATH = ../src
INC_PATH = ../include
CXX = g++-10

cats: ${INC_PATH}/cats.hpp
	$(CXX) -std=c++2a -I../include -Wall -Wextra -Werror -pthread -O2 -c ${SRC_PATH}/cats.cpp
home: ${INC_PATH}/home.hpp
	$(CXX) -std=c++2a -I../include -Wall -Wextra -Werror -pthread -O2 -c ${SRC_PATH}/home.cpp
player: ${INC_PATH}/player.hpp
	$(CXX) -std=c++2a -I../include -Wall -Wextra -Werror -pthread -O2 -c ${SRC_PATH}/player.cpp
main: ${INC_PATH}
	$(CXX) -std=c++2a -I../include -Wall -Wextra -Werror -pthread -O2 -c ${SRC_PATH}/main.cpp

build:
	make cats
	make home
	make player
	make main
	g++ -Wall -Wextra -Werror -pthread -O2 -o cats *.o

clean:
	@rm -r *.o cats

version:
	$(CXX) --version
