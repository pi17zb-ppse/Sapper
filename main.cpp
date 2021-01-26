#include "SapperGame.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1376, 768), "SFMLworks");
	SapperGame game;
	game.Rendering(window);
	return 0;
}