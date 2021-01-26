#include <SFML/Graphics.hpp>
#include "windows.h"

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace std;
using namespace sf;


/**
* Игра сапер
* 
* Класс игры сапер
* 
* @autohor Бондаренко Евгений
* @version 1.0.0.
* @copyright GNU Public License
* @todo Реализовать все методы
*/


class SapperGame {
private:
/**
* Ширина игрового поля
* 
* @var int  $sapperrWidth
* 
* Высота игрового поля
*
* @var int  $sapperrHeight
* 
* Количество ми
* 
* @var int $mines
* 
* Позиция в меню
* 
* @var int $position
*/
	int sapperrWidth;
	int sapperrHeight;
	int mines;
	int position;
public:
	SapperGame();
/**
* Метод взаимодейсвий окон
* @param RenderWindow $window
*/
	void Rendering(RenderWindow& window);
private:
/**
* Метод вызова окна меню
* @param RenderWindow $window
* @return $position
*/
	int windowMenu(RenderWindow& window);

/**
* Метод вызова окна выбора сложности
* @param RenderWindow $window
* @return $position
*/
	int windowSettings(RenderWindow& window);

/**
* Метод вызова окна игры
* @param RenderWindow $window
* @return $position
*/
	int windowGame(RenderWindow& window);

/**
* Метод обхода по пустым клетка
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
*/
	void traversalRecursion(int**& gridLogic, int**& gridView, int X, int Y);

/**
* Метод проверки количеств флажков относительно указателя мины
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
* @param int $gameOver
*/
	void checkMine(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);

/**
* Метод обхода вокруг указателя мины
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
* @param int $gameOver
*/
	void openCells(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);
};

#endif
