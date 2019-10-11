#include "Statistic.hpp"



Statistic::Statistic()
	: font_()
	, text_()
{
	if (!font_.loadFromFile("Media/Fonts/Sansation.ttf"))
	{
	}	// Handle loading error
		
	text_.setFont(font_);
	text_.setPosition(5.f, 5.f);
	text_.setCharacterSize(10);
}

void Statistic::update(sf::Time elapsedTime)
{
	updateTime_ += elapsedTime;
	numFrames_ += 1;

	if (updateTime_ >= sf::seconds(1.0f))
	{
		text_.setString(
			"frames per second:   " + toString(numFrames_) + "\n" +
			"time of frame:   " + toString(updateTime_.asMicroseconds() / numFrames_) + " us");

		updateTime_ -= sf::seconds(1.0f);
		numFrames_ = 0;
	}
}

sf::Text Statistic::getText() const
{
	return text_;
}