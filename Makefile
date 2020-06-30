cats: cats.hpp home.hpp cats.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -pthread -O2 -c cats.cpp
home: home.hpp cats.hpp home.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -pthread -O2 -c home.cpp
player: player.hpp home.hpp cats.hpp player.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -pthread -O2 -c player.cpp
main: main.cpp player.hpp home.hpp cats.hpp player.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -pthread -O2 -c main.cpp
build:
	make cats
	make home
	make player
	make main
	g++ -Wall -Wextra -Werror -pthread -O2 -o cats *.o
clean:
	rm -r *.o cats
