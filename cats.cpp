#include <iostream>
#include <cstdlib>
#include <chrono>
#include "cats.hpp"
#include "home.hpp"

Cat::Cat(std::string name,
	     breeds breed, 
	     Home* homePtr,
	     short int chanceToArive,
         short int stayTime):
         
	     name_  {name},
	     breed_ {breed},
	     homePtr_ {homePtr},
	     chanceToArive_ {chanceToArive},
	     stayTime_ {stayTime} 
{
	inHome = false;
	
	thread_ = std::thread(&Cat::beingACat, this);
}

void Cat::beingACat() {
	while(true) {
		if(inHome) {
			for(short int i = stayTime_; i > 0; i--) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			goOutside();
		} else {
			if( chanceToArive_ == rand() % 100 ) {
				goToHome();
			} else {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	}
}

void Cat::goToHome() {
	this->catMutex_.lock();
	inHome = true;
	homePtr_->catsInHome.push_back(this);
	this->catMutex_.unlock();
	//std::cout << name_ << " in home!" << std::endl;
}

void Cat::goOutside() {
	inHome = false;
	this->catMutex_.lock();
	for(auto i = 0; homePtr_->catsInHome.size(); i++) {
		if(homePtr_->catsInHome[i]->name_ == name_) {
			homePtr_->catsInHome.erase(homePtr_->catsInHome.begin() + i);
			break;
		}
	}
	this->catMutex_.unlock();
	//std::cout << name_ << " go away :c" << std::endl;
}

void Cat::makeCatSound() {
	std::cout << name_ << ": " << "Meow :3" << std::endl;
}
