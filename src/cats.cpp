#include <iostream>
#include <chrono>

#include "cats.hpp"
#include "home.hpp"

extern std::mutex cat_mutex;

Cat::Cat(std::string name,
         Breeds      breed,
         Stats       stats):

         name  {name},
         breed {breed},
         stats {stats}
{
    in_home = false;

    thread = std::thread(&Cat::being_a_cat, this);
}

void Cat::being_a_cat() {
    while(true) {
        if(in_home) {
            for(unsigned char i = stats.staytime; i > 0; i--) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            
            cat_mutex.lock();
            go_outside();
            cat_mutex.unlock();
        } else {
            for(unsigned char i = stats.walktime; i > 0; i--) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            
            while(stats.chance_to_arive != rand() % 100) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            
            cat_mutex.lock();
            stats.visits++;
            go_to_home();
            cat_mutex.unlock();
        }
    }
}

void Cat::go_to_home() {
    home->cats_in_home.push_back(shared_from_this());
    in_home = true;
    std::cout << "  " << name << " in home!" << std::endl;
}

void Cat::go_outside() {
    for(auto i = 0; home->cats_in_home.size(); i++) {
        if(home->cats_in_home[i] == shared_from_this()) {
            home->cats_in_home.erase(home->cats_in_home.begin() + i);
            in_home = false;
            std::cout << "  " << name << " go away :c" << std::endl;
            return;
        }
    }
}

void Cat::makeCatSound() {
    std::cout << "  " << name << ": " << "Meow :3" << std::endl;
}
