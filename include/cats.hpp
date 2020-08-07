#ifndef CATS_HPP
#define CATS_HPP

#include <string>
#include <mutex>
#include <thread>
#include <memory>

#include "home.hpp"

class Cat : public std::enable_shared_from_this<Cat> {
	public:

	enum class breeds {
	    mongrel,
	    turkishAngora,
	    scottishFold,
	    arabianMau,
	    russianBlue,
	    khaoManee
	};

	const std::string name_;
	const breeds breed_;

	Cat(std::string, breeds, short int, short int);

	void makeCatSound();

	private:

	inline static auto home_ = Home::getInstance();
	bool inHome_;
	std::thread thread_;
	inline static std::mutex catMutex_;
	const short int chanceToArive_;
	const short int stayTime_;

	void beingACat();
	void goOutside();
	void goToHome();
};

#endif
