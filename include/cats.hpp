#ifndef CATS_HPP
#define CATS_HPP

#include <string>
#include <mutex>
#include <thread>
#include <memory>

#include "home.hpp"

inline std::mutex cat_mutex;

enum class Breeds {
        mongrel,
        turkish_angora,
        scottish_fold,
        arabian_mau,
        russian_blue,
        khao_manee
};

struct Stats {
    const unsigned char chance_to_arive;
    const unsigned char walktime;
    const unsigned char staytime;
    int                 visits = 0;
};

class Cat final : public std::enable_shared_from_this<Cat> {
public:
    const std::string name;
    const Breeds breed;

    Cat(std::string, Breeds, Stats);
    ~Cat() = default;

    void make_cat_sound();

private:
    Stats stats;

    inline static auto home = Home::get_instance(); // inline because without it doen't work
    bool in_home;
    std::thread thread;
    //inline static std::mutex catMutex;

    void being_a_cat();
    void staying_at_home();
    void walk();
    void go_outside();
    void go_to_home();
};

#endif
