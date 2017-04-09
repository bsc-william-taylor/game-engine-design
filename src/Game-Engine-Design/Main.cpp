
// Include Game Class
#include "FantasyRogue.h"

// Simple rounding function
int RoundUp(float number) {
	// 2.2 will translate to 3
	if(number >= 0) {
		return (int)(number++);
	}

	return NULL;
}

// SDL controls main function
int main(int argc, char * argv[]) {
	FantasyRogue * Game = new FantasyRogue();
	Game->initialise();
	Game->start();
	delete Game;
	return 0;
}
 