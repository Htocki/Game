#include "Label.hpp"



namespace gui
{
	Label::Label(const std::string& text, Widget* parent)
		: Widget(parent)
	{
		text_.setFont(Configuration::fonts.get(Configuration::Fonts::Gui));
		setText(text);
		setTextColor(sf::Color(180, 93, 23));
	}

	Label::~Label() 
	{}

	void Label::setText(const std::string& text)
	{
		text_.setString(text);
		updateShape();
	}

	void Label::setCharacterSize(unsigned int size)
	{
		text_.setCharacterSize(size);
		updateShape();
	}

	unsigned int Label::getCharacterSize() const
	{
		return text_.getCharacterSize();
	}


	void Label::setTextColor(const sf::Color& color)
	{
		text_.setColor(color);
	}

	sf::Vector2f Label::getSize() const
	{
		sf::FloatRect rect = text_.getGlobalBounds();
		return sf::Vector2f(rect.width, rect.height);
	}

	void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform.translate(position_);
		target.draw(text_, states);
	}
}