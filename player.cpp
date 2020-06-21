#include <iostream>
#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

Player::Player(Home* homePtr) : homePtr_ {homePtr} {
	inputCommand();
}

void Player::inputCommand() {
	while(true) {
		std::cout << "Please, enter the command (h (help) for list of all commands):" << std::endl;
		std::string command;
		std::string name;
		std::cin >> command;
		
		if(command == "h") {
			std::cout << "f - (find) all cats in home." << std::endl;
			std::cout << "p - (play) with cat." << std::endl;
			std::cout << "c - (clear) screen." << std::endl;
			std::cout << "e - (exit) from game." << std::endl;
		} else if (command == "f") {
				findCatsInHome();
		} else if (command == "p") {
				std::cout << "Input cat name." << std::endl;
				std::cin >> name;
				playWithCat(selectCatByName(name));
		} else if (command == "c") {
				std::cout << "\x1B[2J\x1B[H";
		} else if (command == "e") {
				std::exit(EXIT_SUCCESS);
		} else {
				std::cout << "Incorrect command." << std::endl;
		}
	}
}

void Player::findCatsInHome() {
	if(homePtr_->catsInHome.size() == 0) {
		std::cout << "No cats in our home :c" << std::endl;
		} else {
			for(auto i : homePtr_->catsInHome) {
				std::cout << i->name_ << std::endl;
			}
		}
}

void Player::playWithCat(Cat* catPtr) {
	if(catPtr != nullptr) {
		catPtr->makeCatSound();
	} else {
		std::cout << "Can't find cat." << std::endl;
	}
}

Cat* Player::selectCatByName(std::string name) {
	for(auto i = 0; homePtr_->catsInHome.size(); i++) {
		if(homePtr_->catsInHome[i]->name_ == name) {
			return homePtr_->catsInHome[i];
		}
	}
	return nullptr;
}
