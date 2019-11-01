#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "ResourceHolder.hpp"
#include "Utility/ToString.hpp"
#include "Statistic.hpp"
#include "Player.hpp"



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
    Label score_;
};

