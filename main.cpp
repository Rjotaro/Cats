#include "player.h"

int main() {
	Home home;
	std::mutex catMutex;
	srand(0);
	
	Cat pepper {"Pepper", Cat::breeds::mongrel, &home, &catMutex};
	Cat snowball {"Snowball", Cat::breeds::turkishAngora, &home, &catMutex};
	Cat socks {"Socks", Cat::breeds::scottishFold, &home, &catMutex};
	
	Player player{&home};
	
	return 0;	
}
