#include <SFML/Graphics.hpp>
#include "windows.h"
#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace sf;

class SapperGame {
private:
	int sapperrWidth = 8;
	int sapperrHeight = 8;
	int mines = 10;
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
