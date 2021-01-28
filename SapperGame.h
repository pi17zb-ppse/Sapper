#include <SFML/Graphics.hpp>
#include "windows.h"

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

using namespace std;
using namespace sf;


/*!
* Игра сапер
* 
* Класс игры сапер
* 
* \author Бондаренко Евгений
* \version 1.0.0.
*/


class SapperGame {
public:

/*!
* Ширина игрового поля
* 
*/

	int sapperrWidth;

/*!
* Высота игрового поля
*
*/

	int sapperrHeight;

/*!
* Количество мин
* 
*/

	int mines;

/*!
* Позиция в меню
* 
*/

	int position;
public:
	SapperGame();

/*!
* Метод взаимодейсвий окон
* \param[out] window - ссылка на объект RenderWindow
*/
	void Rendering(RenderWindow& window);

/*!
* Метод вызова окна меню
* \param[in] window
* \return position - возвращает позицыю перехода
*/

	int windowMenu(RenderWindow& window);

/*!
* Метод вызова окна выбора сложности
* \param[in] window
* \return position - возвращает позицыю перехода
*/

	int windowSettings(RenderWindow& window);

/*!
* Метод вызова окна игры
* \param[in] window
* \return position - возвращает позицыю перехода
*/
	int windowGame(RenderWindow& window);

/*!
* Метод обхода по пустым клетка
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
*/

	void traversalRecursion(int**& gridLogic, int**& gridView, int X, int Y);

/*!
* Метод проверки количеств флажков относительно указателя мины
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
* \param[in] gameOver
*/

	void checkMine(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);

/*!
* Метод обхода вокруг указателя мины
* \param[in] gridLogic
* \param[in] gridView
* \param[in] X
* \param[in] Y
* \param[in] gameOver
*/

	void openCells(int**& gridLogic, int**& gridView, int x, int y, int& gameOver);
};

#endif
