#include <SFML/Graphics.hpp>
#include "windows.h"
#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace sf;

class SapperGame {
public:
	int position;
public:
	SapperGame();
	void Rendering(RenderWindow& window);
private:
	int windowMenu(RenderWindow& window);
	int windowSettings(RenderWindow& window);
	int windowGame(RenderWindow& window);
};

#endif
