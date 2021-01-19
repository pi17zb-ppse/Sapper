#include "SapperGame.h"

SapperGame::SapperGame()
{
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

	while (window.isOpen())
	{
		if (!isMenu)break;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
		position = 0;
		spriteB1.setTextureRect(IntRect(0, 0, 220, 50));
		spriteB2.setTextureRect(IntRect(0, 100, 220, 50));
		spriteB3.setTextureRect(IntRect(0, 0, 325, 100));
		if (IntRect(10, 10, 220, 50).contains(Mouse::getPosition(window))) { spriteB1.setTextureRect(IntRect(0, 50, 220, 50)); position = 1; }
		if (IntRect(10, 65, 220, 50).contains(Mouse::getPosition(window))) { spriteB2.setTextureRect(IntRect(0, 150, 220, 50)); position = 3; }
		if (IntRect(230, 10, 325, 100).contains(Mouse::getPosition(window))) { spriteB3.setTextureRect(IntRect(0, 105, 325, 100)); position = 4; }
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (position > 0)
				isMenu = false;
			if (position == 4)
				position = 0;
		}
		window.clear(Color::White);
		window.draw(spriteB1);
		window.draw(spriteB2);
		window.draw(spriteB3);
		window.display();
	}
	if (position == 1) return 1;
	if (position == 3) return 3;
	return 0;
}
