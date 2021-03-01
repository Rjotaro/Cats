#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

#include "cats.hpp"
#include "home.hpp"
#include "rand.hpp"

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
        walk();
        
        cat_mutex.lock();
        stats.visits++;
        go_to_home();
        cat_mutex.unlock();
        
        staying_at_home();
        
        cat_mutex.lock();
        go_outside();
        cat_mutex.unlock();
    }
}

void Cat::staying_at_home() {
    for(unsigned char i = stats.staytime; i > 0; i--) 
        std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Cat::walk() {
    for(unsigned char i = stats.walktime; i > 0; i--) 
        std::this_thread::sleep_for(std::chrono::seconds(1));
    
    std::uniform_int_distribution<> distrib(0, 99);
            
    while(stats.chance_to_arive < distrib(mersenne))
        std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Cat::go_to_home() {
    home->cats_in_home.push_back(shared_from_this());
    //std::cout << std::endl << "  " << name << " in home!" << std::endl << "> ";
}

void Cat::go_outside() {
    auto i = std::find(std::begin(home->cats_in_home), std::end(home->cats_in_home), shared_from_this());
    if(i != std::end(home->cats_in_home)) {
        home->cats_in_home.erase(i);
        //std::cout << std::endl << "  " << name << " go away :c" << std::endl << "> ";
    }
}

void Cat::make_cat_sound() {
    std::cout << std::endl << "  " << name << ": " << "Meow :3" << std::endl;
}
