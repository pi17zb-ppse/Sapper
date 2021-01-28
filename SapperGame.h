#include <SFML/Graphics.hpp>
#include "windows.h"

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace std;
using namespace sf;


/*!
* ���� �����
* 
* ����� ���� �����
* 
* \author ���������� �������
* \version 1.0.0.
*/


class SapperGame {
public:

/*!
* ������ �������� ����
* 
*/

	int sapperrWidth;

/*!
* ������ �������� ����
*
*/

	int sapperrHeight;

/*!
* ���������� ���
* 
*/

	int mines;

/*!
* ������� � ����
* 
*/

	int position;
public:
	SapperGame();

/*!
* ����� ������������� ����
* \param[out] window - ������ �� ������ RenderWindow
*/
	void Rendering(RenderWindow& window);

/*!
* ����� ������ ���� ����
* \param[in] window
* \return position - ���������� ������� ��������
*/

	int windowMenu(RenderWindow& window);

/*!
* ����� ������ ���� ������ ���������
* \param[in] window
* \return position - ���������� ������� ��������
*/

	int windowSettings(RenderWindow& window);

/*!
* ����� ������ ���� ����
* \param[in] window
* \return position - ���������� ������� ��������
*/
	int windowGame(RenderWindow& window);

/*!
* ����� ������ �� ������ ������
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
*/

	void traversalRecursion(int**& gridLogic, int**& gridView, int X, int Y);

/*!
* ����� �������� ��������� ������� ������������ ��������� ����
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
* \param[in] gameOver
*/

	void checkMine(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);

/*!
* ����� ������ ������ ��������� ����
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
* \param[in] gameOver
*/

	void openCells(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);
};

#endif
