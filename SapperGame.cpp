#include "SapperGame.h"

SapperGame::SapperGame()
{
}

void SapperGame::Rendering(RenderWindow& window)
{
	int position = windowMenu(window);
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

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		spriteB1.setTextureRect(IntRect(0, 0, 250, 50));
		if (IntRect(600, 300, 250, 50).contains(Mouse::getPosition(window))) { spriteB1.setTextureRect(IntRect(0, 50, 250, 50));}
		spriteB2.setTextureRect(IntRect(0, 100, 215, 50));
		if (IntRect(600, 360, 250, 50).contains(Mouse::getPosition(window))) { spriteB2.setTextureRect(IntRect(0, 150, 250, 50));}

		window.clear();
		window.draw(background);
		window.draw(spriteB1);
		window.draw(spriteB2);
		window.display();
	}
	return 0;
}
