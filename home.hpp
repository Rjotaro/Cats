#ifndef HOME_HPP
#define HOME_HPP

#include <vector>

class Cat;

class Home {
	public:

	short int catFood_;
	std::vector<Cat*> catsInHome_;

	static Home& getInstance() {
		static Home instance;
		return instance;
	}

	Home(Home const&) = delete;
  void operator=(Home const&) = delete;

	private:

	Home();
};

#endif
