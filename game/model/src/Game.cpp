#include "Game.h"

Game::Game()
	: window(sf::VideoMode(width, height), "Game")
	, delay(sf::seconds(1.f / 60.f))
	, textures()
	, player(textures)
	, statistic()
	, score({ 230.f, 5.f })
	, framesPerSecond({ 5.f, 5.f })
	, timeOfFrame({ 5.f, 18.f })
{
	Generator<sf::Int64> generator{ 0, 13 };
	Matrix matrix{ 16, 40, generator };

	map.load("media/textures/Space.png",
		sf::Vector2u(30, 30), matrix, 16, 40);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		input();

		while (timeSinceLastUpdate > delay)
		{
			timeSinceLastUpdate -= delay;
			update();
		}

		statistic.update(elapsedTime);
		render();
	}
}

void Game::input()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		}

		player.input(event);
	}
}

void Game::update()
{
	player.update(delay);
	score.setText(toString(player.getName()) + ":   " + toString(player.getScore()));
	framesPerSecond.setText("frames per second:   " + toString(statistic.getFramesPerSecond()));
	timeOfFrame.setText("time of frame:   " + toString(statistic.getTimeOfFrame()));
}

void Game::render()
{
	window.clear(sf::Color::Black);
	window.draw(map);
	player.draw(window, sf::RenderStates::Default);
	score.draw(window, sf::RenderStates::Default);
	framesPerSecond.draw(window, sf::RenderStates::Default);
	timeOfFrame.draw(window, sf::RenderStates::Default);
	window.display();
}
