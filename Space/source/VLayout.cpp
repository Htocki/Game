#include "VLayout.hpp"


namespace gui
{
	VLayout::VLayout(Widget* parent)
		: Layout(parent)
	{}

	VLayout::~VLayout()
	{
		for (Widget* widget : widgets_)
		{
			if (widget->parent_ == this)
				delete widget;
		}
	}

	void VLayout::add(Widget* widget)
	{
		widget->parent_ = this;
		widgets_.emplace_back(widget);
		updateShape();
	}

	Widget* VLayout::at(unsigned int index) const
	{
		return widgets_.at(index);
	}

	sf::Vector2f VLayout::getSize() const
	{
		float max_x = 0;
		float y = 0;

		for (Widget* widget : widgets_)
		{
			sf::Vector2f size = widget->getSize();

			if (size.x > max_x)
				max_x = size.x;

			y += space_ + size.y;
		}
		return sf::Vector2f(max_x + space_ * 2, y + space_);
	}

	bool VLayout::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		for (Widget* widget : widgets_)
		{
			if (widget->processEvent(event, parent_pos))
				return true;
		}
		return false;
	}

	void VLayout::processEvents(const sf::Vector2f& parent_pos)
	{
		for (Widget* widget : widgets_)
			widget->processEvents(parent_pos);
	}

	void VLayout::updateShape()
	{
		float max_x = (parent_ ? parent_->getSize().x : 0);

		for (Widget* widget : widgets_)
		{
			sf::Vector2f size = widget->getSize();
			float widget_x = size.x;

			if (widget_x > max_x)
				max_x = widget_x;
		}

		float pos_y = space_;

		if (parent_)
			pos_y = (parent_->getSize().y - getSize().y) / 2.f;

		for (Widget* widget : widgets_)
		{
			sf::Vector2f size = widget->getSize();
			widget->setPosition((max_x - size.x) / 2.0, pos_y);
			pos_y += size.y + space_;
		}

		Widget::updateShape();
	}

	void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (Widget* widget : widgets_)
			target.draw(*widget, states);
	}
}