#include <iostream>

#include "cats.hpp"
#include "home.hpp"
#include "player.hpp"

extern std::mutex catMutex;

Player::Player() {
	inputCommand();
}

void Player::inputCommand() {
	std::cout << "Please, enter the commands ((help) for list of all commands):" << std::endl;
	while(true) {
		std::cout << ": ";
		std::string command;
		std::cin >> command;
		std::cout << "-----------------------------------------------" << std::endl;

		if(command == "help") {
			std::cout << "(find) all cats in home." << std::endl;
			std::cout << "(play) with cat." << std::endl;
			std::cout << "(bow)'s food level." << std::endl;
			std::cout << "(fill) cat's bow" << std::endl;
			std::cout << "(clear) screen." << std::endl;
			std::cout << "(exit) from game." << std::endl;
		} else if (command == "find") {
				findCatsInHome();
		} else if (command == "play") {
			  catMutex.lock();
				std::cout << "Input cat name: ";
				std::string name;
				std::cin >> name;
				playWithCat(selectCatByName(name));
				catMutex.unlock();
		} else if (command == "bow") {
			std::cout << "Level of food in bow: " << home_->catFood_ << std::endl;
		} else if (command == "fill") {
				fillCatsBow();
				std::cout << "Bow now is full!" << std::endl;
		} else if (command == "clear") {
				std::cout << "\x1B[2J\x1B[H"; // Yeah, it's clean terminal on Linux/bash.
		} else if (command == "exit") {
				std::exit(EXIT_SUCCESS);
		} else {
				std::cout << "Incorrect command, try again." << std::endl;
		}
		std::cout << "-----------------------------------------------" << std::endl;
	}
}

void Player::findCatsInHome() {
	if(home_->catsInHome_.size() != 0) {
			for(auto i : home_->catsInHome_) {
				std::cout << i->name_ << std::endl;
			}
	} else std::cout << "No cats in our home :c" << std::endl;
}

void Player::playWithCat(std::shared_ptr<Cat> catPtr) {
	if(catPtr != nullptr) catPtr->makeCatSound();
	else std::cout << "Can't find cat." << std::endl;
}

std::shared_ptr<Cat> Player::selectCatByName(std::string name) {
	if(home_->catsInHome_.size() != 0) {
		for(auto i : home_->catsInHome_) {
			if(i->name_ == name) return i;
		}
	}
	return nullptr;
}

void Player::fillCatsBow() {
	home_->catFood_ = 100;
}
