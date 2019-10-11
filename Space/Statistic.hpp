#pragma once
#include "StringHelpers.hpp"
#include <SFML/Graphics.hpp>



class Statistic
{
public:
					Statistic();
	void			update(sf::Time elapsedTime);
	sf::Text		getText() const;


private:
	sf::Font				font_;
	sf::Text				text_;
	sf::Time				updateTime_;
	std::size_t				numFrames_;
};