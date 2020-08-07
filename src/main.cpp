#include <memory>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

int main() {
	srand(0);

	auto pepper = std::make_shared<Cat>("Pepper", Cat::breeds::mongrel, 5, 5);
	auto snowball = std::make_shared<Cat>("Snowball", Cat::breeds::turkishAngora, 5, 5);
	auto sock = std::make_shared<Cat>("Socks", Cat::breeds::scottishFold, 5, 5);

	Player player;

	return 0;
}
