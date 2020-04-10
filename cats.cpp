#include <iostream>
#include <cstdlib>
#include <chrono>
#include "home.h"

Cat::Cat(std::string name, breeds breed, Home* homePtr, std::mutex* catMutexPtr) : 
	name_  {name},
	breed_ {breed},
	homePtr_ {homePtr},
	catMutexPtr_ {catMutexPtr}
{
	inHome = false;
	
	thread_ = std::thread(&Cat::beingACat, this);
}

void Cat::beingACat() {
	while(true) {
		if(inHome == false) {
			if( rand() % 100 < 1) {
				catMutexPtr_->lock();
				goToHome();
				catMutexPtr_->unlock();
			} else {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		} else {
			if( rand() % 100 < 5) {
				catMutexPtr_->lock();
				goOutside();
				catMutexPtr_->unlock();
			}
			else {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	}
}

void Cat::goToHome() {
	inHome = true;
	homePtr_->catsInHome.push_back(this);
	//std::cout << name_ << " in home!" << std::endl;
}

void Cat::goOutside() {
	inHome = false;
	for(auto i = 0; homePtr_->catsInHome.size(); i++) {
		if(homePtr_->catsInHome[i]->name_ == name_) {
			homePtr_->catsInHome.erase(homePtr_->catsInHome.begin() + i);
			break;
		}
	}
	//std::cout << name_ << " go away :c" << std::endl;
}
