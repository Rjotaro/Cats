#ifndef HOME_HPP
#define HOME_HPP

#include <vector>

class Cat;

class Home {
	public:
	
	short int catFood_;
	
	Home();
	
	std::vector<Cat*> catsInHome;
};

#endif
