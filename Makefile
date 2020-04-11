cats: cats.h home.h cats.cpp
	g++ -Wall -Wextra -Werror -pthread -O2 -c cats.cpp
home: home.h cats.h home.cpp
	g++ -Wall -Wextra -Werror -pthread -O2 -c home.cpp
player: player.h home.h cats.h player.cpp
	g++ -Wall -Wextra -Werror -pthread -O2 -c player.cpp
main: main.cpp player.h home.h cats.h player.cpp
	g++ -Wall -Wextra -Werror -pthread -O2 -c main.cpp
build:
	make cats
	make home
	make player
	make main
	g++ -Wall -Wextra -Werror -pthread -O2 -o cats *.o
clean:
	rm -r *.o cats
