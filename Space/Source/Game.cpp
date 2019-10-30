#include "Game.hpp"



Game::Game()
	: window_(sf::VideoMode(400, 800), "Space")
	, delay_(sf::seconds(1.f / 60.f))
    , textures_()
    , player_(textures_)
    , statistic_()
    , score_({230.0f, 5.0f})
{
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

        default:   // Добавлена из-за предупреждения комилиятора.
            ;
		}

        player_.processEvents(event);
	}
}

void Game::update()
{
    player_.update(delay_);
    score_.setText(toString(player_.getName()) + ":   " + toString(player_.getScore()));
}

void Game::render()
{
    window_.clear(sf::Color::Black);
    player_.draw(window_, sf::RenderStates::Default);
    statistic_.draw(window_, sf::RenderStates::Default);
    score_.draw(window_, sf::RenderStates::Default);
	window_.display();
}
