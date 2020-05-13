#include "home.h"

class Player {
	public:
	
	Home* homePtr_;
	
	Player(Home*);
	
	void inputCommand();
	void findCatsInHome();
	Cat* selectCatByName(std::string);
	void playWithCat(Cat*);
};
