#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

int main() {
	Home home;
	std::mutex catMutex;
	srand(0);
	
	Cat pepper {"Pepper", Cat::breeds::mongrel, &home, &catMutex, 5, 5};
	Cat snowball {"Snowball", Cat::breeds::turkishAngora, &home, &catMutex, 5, 5};
	Cat socks {"Socks", Cat::breeds::scottishFold, &home, &catMutex, 5, 5};
	
	Player player {&home};
	
	return 0;	
}
