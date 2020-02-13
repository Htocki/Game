#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "ToString.h"
#include "ResourceHolder.h"
#include "Statistic.h"
#include "Player.h"
#include "Tilemap.h"
#include "Generator.h"
#include "RandomizedMatrix.h"



const int width = 400;
const int height = 800;

class Game
{
public:
	Game();
	void run();

private:
	void input();
	void update();
	void render();

	sf::RenderWindow	window_;
	const sf::Time		delay_;

	ResourceHolder <sf::Texture, Textures::ID> textures_;
	Player player_;
	Statistic statistic_;

	Tilemap map_;
	
	Label score_;
	Label framesPerSecond_;
	Label timeOfFrame_;
};