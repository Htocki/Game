#include "Button.hpp"



namespace gui
{
	Button::FuncType Button::defaultFunc = [](const sf::Event&, Button&)->void {};

	Button::Button(Widget* parent)
		: Widget(parent)
		, onClick(defaultFunc)
		, status_(Status::None)
	{}

	Button::~Button()
	{}

	bool Button::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		bool res = false;
		if (event.type == sf::Event::MouseButtonReleased)
		{
			const sf::Vector2f pos = position_ + parent_pos;
			const sf::Vector2f size = getSize();

			sf::FloatRect rect;
			rect.left = pos.x;
			rect.top = pos.y;
			rect.width = size.x;
			rect.height = size.y;

			if (rect.contains(event.mouseButton.x, event.mouseButton.y))
			{
				onClick(event, *this);
				res = true;
			}
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			const sf::Vector2f pos = position_ + parent_pos;
			const sf::Vector2f size = getSize();

			sf::FloatRect rect;
			rect.left = pos.x;
			rect.top = pos.y;
			rect.width = size.x;
			rect.height = size.y;

			int old_status = status_;
			status_ = Status::None;
			const sf::Vector2f mouse_pos(event.mouseMove.x, event.mouseMove.y);

			if (rect.contains(mouse_pos))
				status_ = Status::Hover;

			if ((old_status & Status::Hover) and not (status_ & Status::Hover))
				onMouseLeft();
			else if (not (old_status & Status::Hover) and (status_ & Status::Hover))
				onMouseEntered();
		}
		return res;
	}

	void Button::onMouseEntered()
	{}

	void Button::onMouseLeft()
	{}
}