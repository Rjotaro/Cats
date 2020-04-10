#include "home.h"

class Player {
	public:
	
	Home* homePtr_;
	
	Player(Home*);
	
	void inputCommand();
};
