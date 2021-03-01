#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>
#include <functional>

#include "home.hpp"

class Cat;

class Player final {
public:

    inline static auto home = Home::get_instance(); // inline because without it doen't work
    
    static Player* get_instance() {
        static auto instance = new Player;
        return instance;
    }
    
    Player(Player&&)      = delete;
    Player(Player const&) = delete;
    
    void operator=(Player&&)      = delete;
    void operator=(Player const&) = delete;
    
    void                           find_cats_in_home();
    std::shared_ptr<Cat>           select_cat(std::string);
    void                           play_with_cat();

private:
    Player()  = default;
    ~Player() = default;
//  void fillCatsBow();
};

void input_command(Player* player);
void command_help(Player* player);
void command_find(Player* player);
void command_play(Player* player);
void command_exit(Player* player);

#endif
