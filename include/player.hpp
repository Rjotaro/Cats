#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>

#include "home.hpp"

class Cat;

class Player {
	public:

	inline static auto home_ = Home::getInstance();

	Player();

	void inputCommand();
	void findCatsInHome();
	std::shared_ptr<Cat> selectCatByName(std::string);
	void fillCatsBow();
	void playWithCat(std::shared_ptr<Cat>);
};

#endif
