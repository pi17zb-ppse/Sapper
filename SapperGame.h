#include <SFML/Graphics.hpp>
#include "windows.h"

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace std;
using namespace sf;


/**
* ���� �����
* 
* ����� ���� �����
* 
* @autohor ���������� �������
* @version 1.0.0.
* @copyright GNU Public License
* @todo ����������� ��� ������
*/


class SapperGame {
private:
/**
* ������ �������� ����
* 
* @var int  $sapperrWidth
* 
* ������ �������� ����
*
* @var int  $sapperrHeight
* 
* ���������� ��
* 
* @var int $mines
* 
* ������� � ����
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
* ����� ������������� ����
* @param RenderWindow $window
*/
	void Rendering(RenderWindow& window);
private:
/**
* ����� ������ ���� ����
* @param RenderWindow $window
* @return $position
*/
	int windowMenu(RenderWindow& window);

/**
* ����� ������ ���� ������ ���������
* @param RenderWindow $window
* @return $position
*/
	int windowSettings(RenderWindow& window);

/**
* ����� ������ ���� ����
* @param RenderWindow $window
* @return $position
*/
	int windowGame(RenderWindow& window);

/**
* ����� ������ �� ������ ������
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
*/
	void traversalRecursion(int**& gridLogic, int**& gridView, int X, int Y);

/**
* ����� �������� ��������� ������� ������������ ��������� ����
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
* @param int $gameOver
*/
	void checkMine(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);

/**
* ����� ������ ������ ��������� ����
* @param int $gridLogic
* @param int $gridView
* @param int $X
* @param int $Y
* @param int $gameOver
*/
	void openCells(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);
};

#endif
