#pragma once
#include "Button.hpp"
#include "Label.hpp"



namespace gui
{
	class TextButton : public Button
	{
	public:
		TextButton(const TextButton&) = delete;
		TextButton& operator=(const TextButton&) = delete;


		TextButton(const std::string& text, Widget* parent = nullptr);
		virtual ~TextButton();

		void setText(const std::string& text);
		void setCharacterSize(unsigned int size);
		void setTextColor(const sf::Color& color);
		void setFillColor(const sf::Color& color);
		void setOutlineColor(const sf::Color& color);
		void setOutlineThickness(float thickness);

		virtual sf::Vector2f getSize() const override;

	private:
		sf::RectangleShape shape_;
		Label label_;
		void updateShape() override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		sf::Color fillColor_;
		sf::Color outlineColor_;
		virtual void onMouseEntered() override;
		virtual void onMouseLeft() override;
	};
}