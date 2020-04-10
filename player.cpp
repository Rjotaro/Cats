#include "player.h"
#include <iostream>

Player::Player(Home* homePtr) : homePtr_ {homePtr} {
	inputCommand();
}

void Player::inputCommand() {
	bool wantToQuit {false};
	while(!wantToQuit) {
		std::cout << "Please, enter the command (h (help) for list of all commands):" << std::endl;
		char command;
		std::cin >> command;
		
		switch(command) {
			case 'h':
				std::cout << "s - (show) all cats in home." << std::endl;
				std::cout << "e - (exit) from game." << std::endl;
				break;
			case 's':
				if(homePtr_->catsInHome.size() == 0) {
					std::cout << "No cats in our home :c" << std::endl;
				} else {
					for(auto i : homePtr_->catsInHome) {
						std::cout << i->name_ << std::endl;
					}
				}
				break;
			case 'e':
				wantToQuit = true;
				std::exit(EXIT_SUCCESS);
				break;
			default:
				std::cout << "Incorrect command." << std::endl;
				break;
		}
	}
}
