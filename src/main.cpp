#include <memory>
#include <random>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

//extern std::mutex cat_mutex;

void init() {
    auto pepper   = std::make_shared<Cat>("Pepper", Breeds::mongrel, Stats {3, 5, 5});
    auto snowball = std::make_shared<Cat>("Snowball", Breeds::turkish_angora, Stats {5, 5, 5});
    auto socks    = std::make_shared<Cat>("Socks", Breeds::scottish_fold, Stats {3, 5, 5});
    // All "cats" just pointers on cats because their methos use shared_from_this();
    
    input_command(Player::get_instance());
}

int main() {
    init();
    return 0;
}
