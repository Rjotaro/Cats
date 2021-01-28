#include <iostream>
#include <unordered_map>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

extern std::mutex catMutex;

std::unordered_map<std::string, std::function<void(std::shared_ptr<Player>)>> commands {
    {"help", command_help},
    {"find", command_find},
    {"play", command_play},
    {"exit", command_exit}
};

Player::Player() {
    input_command(get_instance());
}

inline std::shared_ptr<Player> Player::get_instance() {
    return shared_from_this();
}

inline void input_command(std::shared_ptr<Player> player) {
    std::cout << "Please, enter the commands ((help) for list of all commands):" << std::endl;
    
    std::string command;
    while(std::cin >> command) {
        commands[command](player);
    }
}

void Player::findCatsInHome() {
    if(home_->catsInHome_.size() != 0) {
        for(auto i : home_->catsInHome_) std::cout << "  " << i->name_ << std::endl;
    }
    else std::cout << "   No cats in our home :c" << std::endl;
}

void Player::playWithCat() {
    std::cout << "  Input cat name: ";
    std::string name;
    std::cin >> name;
    
    auto catPtr = selectCat(name);
    if(catPtr != nullptr) catPtr->makeCatSound();
    else std::cout << "    Can't find cat." << std::endl;
}

std::shared_ptr<Cat> Player::selectCat(std::string name) {
    if(home_->catsInHome_.size() != 0) {
        for(auto i : home_->catsInHome_) {
            if(i->name_ == name) return i;
        }
    }
    return nullptr;
}

/*void Player::fillCatsBow() {
    home_->catFood_ = 100;
}*/

inline void command_help(std::shared_ptr<Player> player) {
    std::cout << "  (find) all cats in home." << std::endl;
    std::cout << "  (play) with cat." << std::endl;
    std::cout << "  (bow)'s food level." << std::endl;
    std::cout << "  (fill) cat's bow" << std::endl;
    std::cout << "  (clear) screen." << std::endl;
    std::cout << "  (exit) from game." << std::endl;
}

inline void command_find(std::shared_ptr<Player> player) {
    player->findCatsInHome();
}

inline void command_play(std::shared_ptr<Player> player) {
    catMutex.lock();
    player->playWithCat();
    catMutex.unlock();
}

inline void command_exit(std::shared_ptr<Player> player) {
    std::exit(EXIT_SUCCESS);
}
