#include "Widget.hpp"



namespace gui
{
	Widget::Widget(Widget* parent)
		: parent_(parent)
	{}

	Widget::~Widget() 
	{}

	void Widget::setPosition(const sf::Vector2f& pos)
	{
		position_ = pos;
	}

	void Widget::setPosition(float x, float y)
	{
		position_.x = x;
		position_.y = y;
	}

	const sf::Vector2f& Widget::getPosition() const
	{
		return position_;
	}

	bool Widget::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		return false;
	}

	void Widget::processEvents(const sf::Vector2f& parent_pos) 
	{}

	void Widget::updateShape()
	{
		if (parent_)
			parent_->updateShape();
	}
}
