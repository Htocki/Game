#include <exception>
#include <conio.h>
#include "Game.hpp"



int main()
{
	try
	{
		Game game;
		game.gameLoop();
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	_getch();
}




















