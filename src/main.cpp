#include <memory>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

extern std::mutex catMutex;

void init() {
    srand(0); // Random for all game process

    auto pepper = std::make_shared<Cat>("Pepper", Breeds::mongrel, Stats {3, 5, 5});
    auto snowball = std::make_shared<Cat>("Snowball", Breeds::turkishAngora, Stats {5, 5, 5});
    auto socks = std::make_shared<Cat>("Socks", Breeds::scottishFold, Stats {3, 5, 5});
    // All "cats" just pointers on cats because their methos use shared_from_this();

    Player player;
}

int main() {
    init();
    return 0;
}
