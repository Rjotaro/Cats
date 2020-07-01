#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "home.hpp"

class Cat;

class Player {
	public:

	inline static Home& home_ = Home::getInstance();

	Player();

	void inputCommand();
	void findCatsInHome();
	Cat* selectCatByName(std::string);
	void playWithCat(Cat*);
};

#endif
