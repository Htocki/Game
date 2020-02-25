#include "Game.h"

Game::Game()
	: window_(sf::VideoMode(width, height), "Game")
	, delay_(sf::seconds(1.f / 60.f))
	, player_(textures_)
	, score_({ 230.f, 5.f })
	, framesPerSecond_({ 5.f, 5.f })
	, timeOfFrame_({ 5.f, 18.f })
{
	Generator<sf::Int64> generator{ 0, 13 };
	Matrix matrix{ 16, 40, generator };

	map_.load("media/textures/Space.png",
		sf::Vector2u(30, 30), matrix, 16, 40);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		input();

		while (timeSinceLastUpdate > delay_) {
			timeSinceLastUpdate -= delay_;
			update();
		}

		statistic_.update(elapsedTime);
		render();
	}
}

void Game::input()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window_.close();
			break;
		}

		player_.input(event);
	}
}

void Game::update()
{
	player_.update(delay_);
	score_.setText(toString(
		player_.getName()) + 
		":   " + 
		toString(player_.getScore())
	);
	framesPerSecond_.setText(
		"frames per second:   " + 
		toString(statistic_.getFramesPerSecond())
	);
	
	timeOfFrame_.setText(
		"time of frame:   " + 
		toString(statistic_.getTimeOfFrame())
	);
}

void Game::render()
{
	window_.clear(sf::Color::Black);
	window_.draw(map_);
	player_.draw(window_, sf::RenderStates::Default);
	score_.draw(window_, sf::RenderStates::Default);
	framesPerSecond_.draw(window_, sf::RenderStates::Default);
	timeOfFrame_.draw(window_, sf::RenderStates::Default);
	window_.display();
}
