#include "TextButton.hpp"



namespace gui
{
	TextButton::TextButton(const std::string& text, Widget* parent)
		: Button(parent)
		, label_(text, this)
	{
		setFillColor(sf::Color(86, 20, 19));
		setOutlineThickness(5);
		setOutlineColor(sf::Color(146, 20, 19));
	}

	TextButton::~TextButton() {}

	void TextButton::setText(const std::string& text)
	{
		label_.setText(text);
	}

	void TextButton::setCharacterSize(unsigned int size)
	{
		label_.setCharacterSize(size);
	}

	void TextButton::setTextColor(const sf::Color& color)
	{
		label_.setTextColor(color);
	}

	void TextButton::setFillColor(const sf::Color& color)
	{
		fillColor_ = color;
		shape_.setFillColor(fillColor_);
	}

	void TextButton::setOutlineColor(const sf::Color& color)
	{
		outlineColor_ = color;
		shape_.setOutlineColor(outlineColor_);
	}

	void TextButton::setOutlineThickness(float thickness)
	{
		shape_.setOutlineThickness(thickness);
	}

	sf::Vector2f TextButton::getSize() const
	{
		sf::FloatRect rect = shape_.getGlobalBounds();
		return sf::Vector2f(rect.width, rect.height);
	}

	void TextButton::updateShape()
	{
		sf::Vector2f label_size = label_.getSize();
		unsigned int char_size = label_.getCharacterSize();

		shape_.setSize(
			sf::Vector2f(
				char_size * 2 + label_size.x,
				char_size * 2 + label_size.y
			)
		);

		label_.setPosition(char_size, char_size);
		Widget::updateShape();
	}

	void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform.translate(position_);
		target.draw(shape_, states);
		target.draw(label_, states);
	}

	void TextButton::onMouseEntered()
	{
		const float light = 1.4f;

		shape_.setOutlineColor(
			sf::Color(
				outlineColor_.r * light,
				outlineColor_.g * light,
				outlineColor_.b * light
			)
		);

		shape_.setFillColor(
			sf::Color(
				fillColor_.r * light,
				fillColor_.g * light,
				fillColor_.b * light
			)
		);
	}

	void TextButton::onMouseLeft()
	{
		shape_.setOutlineColor(outlineColor_);
		shape_.setFillColor(fillColor_);
	}
}