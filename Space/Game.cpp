#include "Game.hpp"



Game::Game()
	: window_(sf::VideoMode(400, 800), "Space")
	, delay_(sf::seconds(1.f / 60.f))
	, aircraft_()
	, statistic_()
{
	// Try to load resources
	textures_.load(Textures::Landscape, "Media/Textures/Desert.png");
	textures_.load(Textures::Airplane, "Media/Textures/Eagle.png");

	// Access resources
	aircraft_.setTexture(textures_.get(Textures::Airplane));
}

void Game::gameLoop()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		processEvents();

		while (timeSinceLastUpdate > delay_)
		{
			timeSinceLastUpdate -= delay_;
			update();
		}

		statistic_.update(elapsedTime);
		render();
	}
}

void Game::processEvents()
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

		aircraft_.processEvents(event);
	}
}

void Game::update()
{
	aircraft_.update(delay_);
}

void Game::render()
{
	window_.clear();
	window_.draw(aircraft_.getSprite());
	window_.draw(statistic_.getText());
	window_.display();
}