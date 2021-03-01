#ifndef HOME_HPP
#define HOME_HPP

#include <vector>
#include <memory>

class Cat;

class Home final {
public:
    unsigned short cat_food {0};
    std::vector<std::shared_ptr<Cat>> cats_in_home;

    // All shit below for making Home class singltone
    static std::shared_ptr<Home> get_instance() {
        static auto instance = std::shared_ptr<Home>(new Home);
        return instance;
    }

    Home(Home&&)      = delete;
    Home(Home const&) = delete;
    ~Home() = default;
    
    void operator=(Home&&)      = delete;
    void operator=(Home const&) = delete;

private:
    Home()  = default;
};

#endif
