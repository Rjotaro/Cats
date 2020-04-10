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

	Cat(std::string, breeds, Home*, std::mutex*);
	
	private:
	
	Home* const homePtr_;
	bool inHome;
	std::thread thread_;
	std::mutex* catMutexPtr_;
	
	void beingACat();
	void goOutside();
	void goToHome();
};
