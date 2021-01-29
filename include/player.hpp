#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>
#include <functional>

#include "home.hpp"

class Cat;

class Player : public std::enable_shared_from_this<Player> {
public:

    inline static auto home_ = Home::get_instance(); // inline because without it doen't work

    Player(Player const&) = delete;
    void operator=(Player const&) = delete;
    
    static std::shared_ptr<Player> get_instance() {
      static auto instance = std::shared_ptr<Player>(new Player);
      return instance;
    }
    
    void                           find_cats_in_home();
    std::shared_ptr<Cat>           select_cat(std::string);
    void                           play_with_cat();

private:
    Player() = default;
//  void fillCatsBow();
};

void input_command(std::shared_ptr<Player> player);
void command_help(std::shared_ptr<Player> player);
void command_find(std::shared_ptr<Player> player);
void command_play(std::shared_ptr<Player> player);
void command_exit(std::shared_ptr<Player> player);

#endif
