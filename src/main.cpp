#include <SFML/Graphics.hpp>

#include "game.hpp"


const char _font_location[] = "/home/arnab/CodeAyan/pong/src/roboto.ttf";

int main()
{
	Game pong;
	pong.run();
	return 0;
}

// cmake -B build && cmake --build build
