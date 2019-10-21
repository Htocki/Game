#include "Container.hpp"



namespace gui
{
	Container::Container(Widget* parent)
		: Widget(parent)
		, layout_(nullptr)
	{}

	Container::~Container()
	{
		if (layout_ != nullptr and layout_->parent_ == this)
		{
			layout_->parent_ = nullptr;
			delete layout_;
		}
	}

	void Container::setLayout(Layout* layout)
	{
		if (layout_ != nullptr and layout_->parent_ == this)
		{
			layout_->parent_ = nullptr;
			delete layout_;
		}

		if ((layout_ = layout) != nullptr)
		{
			layout_->parent_ = this;
			layout_->updateShape();
		}
	}

	Layout* Container::getLayout() const
	{
		return layout_;
	}

	sf::Vector2f Container::getSize() const
	{
		sf::Vector2f res(0, 0);
		if (layout_)
			res = layout_->getSize();
		return res;
	}

	void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (layout_)
			target.draw(*layout_, states);
	}

	bool Container::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		bool res = false;
		if (not res and layout_)
			res = layout_->processEvent(event, parent_pos);
		return res;
	}

	void Container::processEvents(const sf::Vector2f& parent_pos)
	{
		if (layout_)
			layout_->processEvents(parent_pos);
	}
}