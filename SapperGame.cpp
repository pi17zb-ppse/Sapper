#include "SapperGame.h"

SapperGame::SapperGame()
{
	sapperrWidth = 8;
	sapperrHeight = 8;
	mines = 10;
	position = 0;
}

void SapperGame::Rendering(RenderWindow& window)
{
	int position = windowMenu(window);
	while (window.isOpen())
	{
		Sleep(50);
		if (position == 0)
			position = windowMenu(window);
		if (position == 1)
			position = windowGame(window);
		if (position == 2)
			position = windowSettings(window);
		if (position == 3)
			position = windowSettings(window);
		if (position > 3)
			position = 0;
	}
}

int SapperGame::windowMenu(RenderWindow& window)
{
	Texture button, backgroundTexture;
	button.loadFromFile("Image/128.png");
	backgroundTexture.loadFromFile("Image/2.jpg");
	Sprite spriteB1(button), spriteB2(button), background(backgroundTexture);
	background.setPosition(6, 0);
	spriteB1.setTextureRect(IntRect(0, 0, 250, 50));
	spriteB1.setPosition(600, 300);
	spriteB2.setTextureRect(IntRect(0, 100, 215, 50));
	spriteB2.setPosition(600, 360);
	bool isMenu = true;

	while (window.isOpen())
	{
		if (!isMenu) break;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		spriteB1.setTextureRect(IntRect(0, 0, 250, 50));
		position = 0;
		if (IntRect(600, 300, 250, 50).contains(Mouse::getPosition(window))) { spriteB1.setTextureRect(IntRect(0, 50, 250, 50)); position = 1;}
		spriteB2.setTextureRect(IntRect(0, 100, 215, 50));
		if (IntRect(600, 360, 250, 50).contains(Mouse::getPosition(window))) { spriteB2.setTextureRect(IntRect(0, 150, 250, 50)); position = 2;}
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (position > 0)
				isMenu = false;
		}
		window.clear();
		window.draw(background);
		window.draw(spriteB1);
		window.draw(spriteB2);
		window.display();
	}

	if (position == 1)
		return 1;
	if (position == 2)
		return 2;
	return 0;
}

int SapperGame::windowSettings(RenderWindow& window)
{
	Sleep(50);
	Texture button, button2, backgroundTexture;
	button.loadFromFile("Image/130.png");
	button2.loadFromFile("Image/131.png");
	backgroundTexture.loadFromFile("Image/2.jpg");
	Sprite spriteB1(button), spriteB2(button), spriteB3(button), spriteB4(button2), background(backgroundTexture);
	background.setPosition(6, 0);
	spriteB1.setPosition(520, 200);
	spriteB2.setPosition(520, 310);
	spriteB3.setPosition(520, 420);
	spriteB4.setPosition(10, 10);

	bool isMenu = true;
	Sleep(50);
	while (window.isOpen())
	{
		if (!isMenu)break;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		int position1 = 0;
		spriteB1.setTextureRect(IntRect(0, 0, 326, 100));
		if (IntRect(520, 200, 326, 100).contains(Mouse::getPosition(window))) { spriteB1.setTextureRect(IntRect(0, 105, 326, 100)); position1 = 1; }
		spriteB2.setTextureRect(IntRect(0, 210, 326, 100));
		if (IntRect(520, 310, 326, 100).contains(Mouse::getPosition(window))) { spriteB2.setTextureRect(IntRect(0, 315, 326, 100)); position1 = 2; }
		spriteB3.setTextureRect(IntRect(0, 420, 326, 100));
		if (IntRect(520, 420, 326, 100).contains(Mouse::getPosition(window))) { spriteB3.setTextureRect(IntRect(0, 525, 326, 100)); position1 = 3; }
		spriteB4.setTextureRect(IntRect(0, 0, 326, 100));
		if (IntRect(0, 0, 326, 100).contains(Mouse::getPosition(window))) { spriteB4.setTextureRect(IntRect(0, 105, 326, 100)); position1 = 4; }


		if (Mouse::isButtonPressed(Mouse::Left))
		{

			if (position1 > 0)
				isMenu = false;
			if (position1 == 1)
			{
				sapperrWidth = 8;
				sapperrHeight = 8;
				mines = 10;
			}
			if (position1 == 2)
			{
				sapperrWidth = 16;
				sapperrHeight = 16;
				mines = 40;
			}
			if (position1 == 3)
			{
				sapperrWidth = 30;
				sapperrHeight = 16;
				mines = 99;
			}
			if (position1 == 4)
			{
				position = 0;
			}
		}

		window.clear();
		window.draw(background);
		window.draw(spriteB1);
		window.draw(spriteB2);
		window.draw(spriteB3);
		window.draw(spriteB4);
		window.display();
	}
	if (position == 3)return 1;
	return 0;
}

int SapperGame::windowGame(RenderWindow& window)
{
	Sleep(50);
	bool isMenu = true;
	Texture button, button2, button3;
	button.loadFromFile("Image/128.png");
	button2.loadFromFile("Image/128.png");
	button3.loadFromFile("Image/131.png");
	Sprite spriteB1(button), spriteB2(button2), spriteB3(button3);
	spriteB1.setTextureRect(IntRect(0, 0, 220, 50));
	spriteB1.setPosition(10, 10);
	spriteB2.setTextureRect(IntRect(0, 100, 220, 50));
	spriteB2.setPosition(10, 65);
	spriteB3.setTextureRect(IntRect(0, 0, 325, 100));
	spriteB3.setPosition(230, 10);

	int xPosition = 200;
	int yPosition = 100;
	int w = 32;
	int minesR = mines;
	String str;
	int gameOver = 0;
	bool startGame = true;
	int** gridLogic = new int* [sapperrWidth];

	for (int i = 0; i < sapperrWidth; i++)
		gridLogic[i] = new int[sapperrHeight];

	for (int i = 0; i < sapperrWidth; i++)
	{
		for (int j = 0; j < sapperrHeight; j++)
			gridLogic[i][j] = 0;
	}

	int** gridView = new int* [sapperrWidth];

	for (int i = 0; i < sapperrWidth; i++)
		gridView[i] = new int[sapperrHeight];

	// Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("Image/tiles.jpg");
	Sprite s(t);

	for (int i = 0; i < sapperrWidth; i++)
		for (int j = 0; j < sapperrHeight; j++)
		{
			gridView[i][j] = 10;
		}

	while (window.isOpen())
	{
		if (!isMenu)break;

		// Получаем координаты курсора мышки относительно окна нашего приложения

		int x = -1;
		int y = -1;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			// Определяем, была ли нажата кнопка мыши?
			if (e.type == Event::MouseButtonPressed) {

				if (IntRect(((0 + 2) * w) + xPosition, ((0 + 2) * w) + yPosition,
					(sapperrWidth * w),
					(sapperrHeight * w)).contains(Mouse::getPosition(window)))
				{
					for (int i = 0; i < sapperrWidth; i++) {
						for (int j = 0; j < sapperrHeight; j++)
						{
							if (IntRect(((i + 2) * w) + xPosition,
								((j + 2) * w) + yPosition, w, w)
								.contains(Mouse::getPosition(window)))
							{
								x = i;
								y = j;
								if (startGame)
								{
									startGame = false;

									for (int i = 0; i < mines;)
									{
										int naberW = rand() % (sapperrWidth - 1) + 1;
										int naberH = rand() % (sapperrHeight - 1) + 1;
										if (gridLogic[naberW][naberH] == 0 && naberW != x && naberH != y)
										{
											gridLogic[naberW][naberH] = 9;
											i++;
										}
									}
									// Подсчет мин вокруг каждой клетки	
									for (int i = 0; i < sapperrWidth; i++) {
										for (int j = 0; j < sapperrHeight; j++)
										{
											if (gridLogic[i][j] == 9)
											{
												if (i != 0)
												{
													if (gridLogic[i - 1][j] != 9)
														gridLogic[i - 1][j] += 1;
												}
												if (j != 0)
												{
													if (gridLogic[i][j - 1] != 9)
														gridLogic[i][j - 1] += 1;
												}
												if (i != sapperrWidth - 1)
												{
													if (gridLogic[i + 1][j] != 9)
														gridLogic[i + 1][j] += 1;
												}
												if (j != sapperrHeight - 1)
												{
													if (gridLogic[i][j + 1] != 9)
														gridLogic[i][j + 1] += 1;
												}
												if (i != 0 && j != 0)
												{
													if (gridLogic[i - 1][j - 1] != 9)
														gridLogic[i - 1][j - 1] += 1;
												}
												if (i != 0 && j != sapperrHeight - 1)
												{
													if (gridLogic[i - 1][j + 1] != 9)
														gridLogic[i - 1][j + 1] += 1;
												}
												if (i != sapperrWidth - 1 && j != 0)
												{
													if (gridLogic[i + 1][j - 1] != 9)
														gridLogic[i + 1][j - 1] += 1;
												}
												if (i != sapperrWidth - 1 && j != sapperrHeight - 1)
												{
													if (gridLogic[i + 1][j + 1] != 9)
														gridLogic[i + 1][j + 1] += 1;
												}
											}
										}
									}
								}
							}
						}
					}
					if (e.key.code == Mouse::Left)
					{
						if (x < sapperrWidth && y < sapperrHeight && x > -1 && y > -1)
						{
							gridView[x][y] = gridLogic[x][y];
							if (gridLogic[x][y] == 9)
								gameOver = 1;
							gridView[x][y] = gridLogic[x][y];
						}
					}
					// Если была нажата правая кнопка мыши, то отображаем флажок
					if (e.key.code == Mouse::Right)
					{
						if (x < sapperrWidth && y < sapperrHeight && x > -1 && y > -1)
						{
							if (gridView[x][y] == 10 && minesR > 0)
							{
								gridView[x][y] = 11;
							}
							else if (gridView[x][y] == 11 && minesR <= mines)
							{
								gridView[x][y] = 10;
							}
						}
						if (minesR == 0)
						{
							for (int i = 0; i < sapperrWidth; i++)
								for (int j = 0; j < sapperrHeight; j++)
								{
									if (gridView[x][y] != 0)
									{
										if (i == sapperrWidth - 1 && j == sapperrHeight - 1)
											gameOver = 2;
									}
									else
										break;
								}
						}
					}
				}
			}
		}
		//
		position = 0;
		spriteB1.setTextureRect(IntRect(0, 0, 220, 50));
		spriteB2.setTextureRect(IntRect(0, 100, 220, 50));
		spriteB3.setTextureRect(IntRect(0, 0, 325, 100));
		if (IntRect(10, 10, 220, 50).contains(Mouse::getPosition(window))) { spriteB1.setTextureRect(IntRect(0, 50, 220, 50)); position = 1; }
		if (IntRect(10, 65, 220, 50).contains(Mouse::getPosition(window))) { spriteB2.setTextureRect(IntRect(0, 150, 220, 50)); position = 3; }
		if (IntRect(230, 10, 325, 100).contains(Mouse::getPosition(window))) { spriteB3.setTextureRect(IntRect(0, 105, 325, 100)); position = 4; }
		if (IntRect(10, 10, 220, 50).contains(Mouse::getPosition(window)))
		{
			spriteB1.setTextureRect(IntRect(0, 50, 220, 50));
			position = 1;
		}
		if (IntRect(10, 65, 220, 50).contains(Mouse::getPosition(window)))
		{
			spriteB2.setTextureRect(IntRect(0, 150, 220, 50));
			position = 3;
		}
		if (IntRect(230, 10, 325, 100).contains(Mouse::getPosition(window)))
		{
			spriteB3.setTextureRect(IntRect(0, 105, 325, 100));
			position = 4;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (position > 0)
				isMenu = false;
			if (position == 4)
				position = 0;
		}
		//

		window.clear(Color::White);
		if (gameOver != 2)
		{
			for (int i = 0; i < sapperrWidth; i++)
				for (int j = 0; j < sapperrHeight; j++)
				{
					if (gameOver == 1)
						gridView[i][j] = gridLogic[i][j];
					s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
					s.setPosition(((i + 2) * w) + xPosition, ((j + 2) * w) + yPosition);
					window.draw(s);
				}
		}

		//

		window.draw(spriteB1);
		window.draw(spriteB2);
		window.draw(spriteB3);
		//
		window.display();
	}
	for (int i = 0; i < sapperrWidth; i++)
		delete[]gridLogic[i];
	delete[]gridLogic;

	for (int i = 0; i < sapperrWidth; i++)
		delete[]gridView[i];
	delete[]gridView;
	if (position == 1) return 1;
	if (position == 3) return 3;
	return 0;
}
