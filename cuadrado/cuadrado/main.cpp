#include <iostream>
#include "../deps/include/SDL.h"
#include "window.h"

#pragma comment(lib,"../deps/lib/SDL2.lib")
#pragma comment(lib,"../deps/lib/SDL2main.lib")

using namespace std;


int main(int argv, char *argc[])
{	
	window window("Shooting Square", 750, 600);
	while (!window.isClosed()) {

	}
	return 0;
}