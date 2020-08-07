#include <iostream>
#include <cstdlib>
#include <chrono>

#include "cats.hpp"
#include "home.hpp"

extern std::mutex catMutex;

Cat::Cat(std::string name,
	     breeds breed,
	     short int chanceToArive,
	     short int stayTime):

	     name_  {name},
	     breed_ {breed},
	     chanceToArive_ {chanceToArive},
	     stayTime_ {stayTime}
{
	inHome_ = false;

	thread_ = std::thread(&Cat::beingACat, this);
}

void Cat::beingACat() {
	while(true) {
		if(inHome_) {
			for(short int i = stayTime_; i > 0; i--) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			catMutex.lock();
			goOutside();
			catMutex.unlock();
		} else {
			if(chanceToArive_ == rand() % 100) {
				catMutex.lock();
				goToHome();
				catMutex.unlock();
			} else std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

void Cat::goToHome() {
	home_->catsInHome_.push_back(shared_from_this());
	inHome_ = true;
//	std::cout << name_ << " in home!" << std::endl;
}

void Cat::goOutside() {
	for(auto i = 0; home_->catsInHome_.size(); i++) {
		if(home_->catsInHome_[i]->name_ == name_) {
			home_->catsInHome_.erase(home_->catsInHome_.begin() + i);
			inHome_ = false;
			return;
		}
	}
//	std::cout << name_ << " go away :c" << std::endl;
}

void Cat::makeCatSound() {
	std::cout << name_ << ": " << "Meow :3" << std::endl;
}
