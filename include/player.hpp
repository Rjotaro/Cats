#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>

#include "home.hpp"

class Cat;

class Player {
	public:

	inline static auto home_ = Home::getInstance(); // inline because without it doen't work

	Player();

	void inputCommand();
	void findCatsInHome();
	void playWithCat(std::shared_ptr<Cat>);
	std::shared_ptr<Cat> selectCatByName(std::string);
	void fillCatsBow();
};

#endif
