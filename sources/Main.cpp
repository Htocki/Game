#include <exception>
#include <iostream>
#include "includes/Game.hpp"



int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
