#include <iostream>
#include <unordered_map>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

// extern std::mutex cat_mutex;

std::unordered_map<std::string, std::function<void(std::shared_ptr<Player>)>> commands {
    {"help", command_help},
    {"find", command_find},
    {"play", command_play},
    {"exit", command_exit}
};

void Player::find_cats_in_home() {
    if(home_->cats_in_home.size() != 0)
        for(auto i : home_->cats_in_home) std::cout << "  " << i->name << std::endl;
    else std::cout << "No cats in our home :c" << std::endl;
}

std::shared_ptr<Cat> Player::select_cat(std::string name) {
    if(home_->cats_in_home.size() != 0)
        for(auto i : home_->cats_in_home)
            if(i->name == name) return i;
    return nullptr;
}

void Player::play_with_cat() {
    std::cout << "Input cat name: ";
    std::string name;
    std::cin >> name;
    
    auto cat_ptr = select_cat(name);
    if(cat_ptr != nullptr) cat_ptr->makeCatSound();
    else std::cout << "Can't find cat." << std::endl;
}


void input_command(std::shared_ptr<Player> player) {
    std::cout << "Please, enter the commands ((help) for list of all commands):" << std::endl;
    
    std::string command;
    while(std::cin >> command) {
        if(commands.find(command) == commands.end()) 
            std::cout << "This command don't exist" << std::endl;
        else commands[command](player);
    }
}

void command_help(std::shared_ptr<Player> player) {
    std::cout << "  (find) all cats in home." << std::endl;
    std::cout << "  (play) with cat." << std::endl;
    std::cout << "  (bow)'s food level." << std::endl;
    std::cout << "  (fill) cat's bow" << std::endl;
    std::cout << "  (exit) from game." << std::endl;
}

void command_find(std::shared_ptr<Player> player) {
    player->find_cats_in_home();
}

void command_play(std::shared_ptr<Player> player) {
    cat_mutex.lock();
    player->play_with_cat();
    cat_mutex.unlock();
}

void command_exit(std::shared_ptr<Player> player) {
    std::exit(EXIT_SUCCESS);
}
