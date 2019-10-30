#pragma once
#include "Widget.hpp"
#include <string>



namespace gui
{
	class Label : public Widget
	{
	public:
		Label(const Label&) = delete;
		Label& operator=(const Label&) = delete;

		Label(const std::string& text, Widget* parent = nullptr);
		virtual ~Label();

		void setText(const std::string& text);
		void setCharacterSize(unsigned int size);
		unsigned int getCharacterSize() const;
		void setTextColor(const sf::Color& color);
		virtual sf::Vector2f getSize() const override;

	private:
		sf::Text text_;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
