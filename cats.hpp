#ifndef CATS_HPP
#define CATS_HPP
#include <string>
#include <mutex>
#include <thread>

class Home;

class Cat {
	public:
	
	enum class breeds {
	    mongrel,
	    turkishAngora,
	    scottishFold,
	    arabianMau,
	    russianBlue
	};
	
	const std::string name_;
	const breeds breed_;

	Cat(std::string, breeds, Home*, short int, short int);
	
	void makeCatSound();
	
	private:
	
	Home* const homePtr_;
	bool inHome;
	std::thread thread_;
	inline static std::mutex catMutex_;
	const short int chanceToArive_;
	const short int stayTime_;
	
	void beingACat();
	void goOutside();
	void goToHome();
};

#endif
