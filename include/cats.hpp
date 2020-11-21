#ifndef CATS_HPP
#define CATS_HPP

#include <string>
#include <mutex>
#include <thread>
#include <memory>

#include "home.hpp"

inline std::mutex catMutex;

enum class Breeds {
        mongrel,
        turkishAngora,
        scottishFold,
        arabianMau,
        russianBlue,
        khaoManee
};

struct Stats {
    const unsigned char chanceToArive_;
    const unsigned char stayTime_;
    int                 visits_ = 0;
};

class Cat : public std::enable_shared_from_this<Cat> {
public:
    const std::string name_;
    const Breeds breed_;

    Cat(std::string, Breeds, Stats);


    void makeCatSound();

private:
    Stats stats_;

    inline static auto home_ = Home::getInstance(); // inline because without it doen't work
    bool inHome_;
    std::thread thread_;
    //inline static std::mutex catMutex;

    void beingACat();
    void goOutside();
    void goToHome();
};

#endif
