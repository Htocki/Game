#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Aircraft.hpp"
#include "Statistic.hpp"



class Game
{
public:
	Game();
	void gameLoop();

private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow	window_;
	const sf::Time		delay_;

	Aircraft	aircraft_;
	Statistic	statistic_;

	ResourceHolder <sf::Texture, Textures::ID> textures_;
};

