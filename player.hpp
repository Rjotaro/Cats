#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Home;
class Cat;

class Player {
	public:
	
	Home* homePtr_;
	
	Player(Home*);
	
	void inputCommand();
	void findCatsInHome();
	Cat* selectCatByName(std::string);
	void playWithCat(Cat*);
};

#endif
