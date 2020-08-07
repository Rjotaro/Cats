#include <iostream>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

Player::Player() {
	inputCommand();
}

void Player::inputCommand() {
	while(true) {
		std::cout << "Please, enter the command ((help) for list of all commands):" << std::endl;
		std::string command;
		std::cin >> command;

		if(command == "help") {
			std::cout << "(find) all cats in home." << std::endl;
			std::cout << "(play) with cat." << std::endl;
			std::cout << "(fill) cat's bow" << std::endl;
			std::cout << "(clear) screen." << std::endl;
			std::cout << "(exit) from game." << std::endl;
		} else if (command == "find") {
				findCatsInHome();
		} else if (command == "play") {
				std::cout << "Input cat name." << std::endl;
				std::string name;
				std::cin >> name;
				playWithCat(selectCatByName(name));
		} else if (command == "fill") {
				fillCatsBow();
		} else if (command == "clear") {
				std::cout << "\x1B[2J\x1B[H";
		} else if (command == "exit") {
				std::exit(EXIT_SUCCESS);
		} else {
				std::cout << "Incorrect command." << std::endl;
		}
	}
}

void Player::findCatsInHome() {
	if(home_->catsInHome_.size() == 0) {
		std::cout << "No cats in our home :c" << std::endl;
		} else {
			for(auto i : home_->catsInHome_) {
				std::cout << i->name_ << std::endl;
			}
		}
}

std::shared_ptr<Cat> Player::selectCatByName(std::string name) {
	for(short int i = 0; home_->catsInHome_.size(); i++) {
		if(home_->catsInHome_[i]->name_ == name) {
			return home_->catsInHome_[i];
		}
	}
	return nullptr;
}

void Player::fillCatsBow() {
	home_->catFood_ = 100;
}

void Player::playWithCat(std::shared_ptr<Cat> catPtr) {
	if(catPtr != nullptr) {
		catPtr->makeCatSound();
	} else {
		std::cout << "Can't find cat." << std::endl;
	}
}
