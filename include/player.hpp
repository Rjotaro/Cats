#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>
#include <functional>

#include "home.hpp"

class Cat;

class Player : std::enable_shared_from_this<Player> {
public:

    inline static auto home_ = Home::getInstance(); // inline because without it doen't work

    Player();
    
    inline std::shared_ptr<Player> get_instance();
    void                           findCatsInHome();
    std::shared_ptr<Cat>           selectCat(std::string);
    void                           playWithCat();
//  void fillCatsBow();
};

inline void input_command(std::shared_ptr<Player> player);
inline void command_help(std::shared_ptr<Player> player);
inline void command_find(std::shared_ptr<Player> player);
inline void command_play(std::shared_ptr<Player> player);
inline void command_exit(std::shared_ptr<Player> player);

#endif
