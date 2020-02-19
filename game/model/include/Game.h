#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Generator.h"
#include "Player.h"
#include "Matrix.h"
#include "ResourceHolder.h"
#include "Statistic.h"
#include "Tilemap.h"
#include "ToString.h"

constexpr sf::Int64 width = { 400 };
constexpr sf::Int64 height = { 800 };

class Game
{
public:
	Game();
	void run();

private:
	void input();
	void update();
	void render();

	sf::RenderWindow window;
	const sf::Time delay;

	ResourceHolder <sf::Texture, Textures::ID> textures;
	Player player;
	Statistic statistic;

	Tilemap map;

	Label score;
	Label framesPerSecond;
	Label timeOfFrame;
};
