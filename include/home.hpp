#ifndef HOME_HPP
#define HOME_HPP

#include <vector>
#include <memory>

class Cat;

class Home {
public:
	unsigned short catFood_ {0};
	std::vector<std::shared_ptr<Cat>> catsInHome_;

  // All shit below for making Home class singltone
	static std::shared_ptr<Home> getInstance() {
		static auto instance = std::shared_ptr<Home>(new Home);
	  return instance;
	}

	Home(Home const&) = delete;
	void operator=(Home const&) = delete;

private:
	Home() = default;
};

#endif
