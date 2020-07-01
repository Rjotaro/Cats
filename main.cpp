#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

int main() {
	srand(0);

	Cat pepper {"Pepper", Cat::breeds::mongrel, 5, 5};
	Cat snowball {"Snowball", Cat::breeds::turkishAngora, 5, 5};
	Cat socks {"Socks", Cat::breeds::scottishFold, 5, 5};

	Player player;

	return 0;
}
