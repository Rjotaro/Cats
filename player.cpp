#include "player.h"
#include <iostream>

Player::Player(Home* homePtr) : homePtr_ {homePtr} {
	inputCommand();
}

void Player::inputCommand() {
	while(true) {
		std::cout << "Please, enter the command (h (help) for list of all commands):" << std::endl;
		char command;
		std::string name;
		std::cin >> command;
		
		switch(command) {
			case 'h':
				std::cout << "f - (find) all cats in home." << std::endl;
				std::cout << "p - (play) with cat." << std::endl;
				std::cout << "c - (clear) screen." << std::endl;
				std::cout << "e - (exit) from game." << std::endl;
				break;
			case 'f':
				findCatsInHome();
				break;
			case 'p':
				std::cout << "Input cat name." << std::endl;
				std::cin >> name;
				playWithCat(selectCatByName(name));
				break;
			case 'c':
				std::cout << "\x1B[2J\x1B[H";
				break;
			case 'e':
				std::exit(EXIT_SUCCESS);
				break;
			default:
				std::cout << "Incorrect command." << std::endl;
				break;
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

void Player::playWithCat(Cat* cat) {
	if(cat != nullptr) {
		cat->makeCatSound();
	} else {
		std::cout << "Can't find cat." << std::endl;
	}
}

Cat* Player::selectCatByName(std::string name) {
	for(auto i = 0; homePtr_->catsInHome.size(); i++) {
		if(homePtr_->catsInHome[i]->name_ == name) {
			return homePtr_->catsInHome[i];
			break;
		}
	}
	return nullptr;
}
