#include "Frame.hpp"



namespace gui
{
	Frame::Frame(sf::RenderWindow& window)
		: Container(nullptr)
		, ActionTarget(Configuration::gui_inpugs)
		, window_(window)
	{}

	Frame::~Frame()
	{}

	void Frame::draw()
	{
		window_.draw(*this);
	}

	void Frame::bind(int key, const FuncType& callback)
	{
		ActionTarget::bind(key, callback);
	}

	void Frame::unbind(int key)
	{
		ActionTarget::unbind(key);
	}

	sf::Vector2f Frame::getSize() const
	{
		sf::Vector2u size = window_.getSize();
		return sf::Vector2f(size.x, size.y);
	}

	void Frame::processEvents()
	{
		sf::Vector2f parent_pos(0, 0);
		processEvents(parent_pos);
	}

	bool Frame::processEvent(const sf::Event& event)
	{
		sf::Vector2f parent_pos(0, 0);
		return processEvent(event, parent_pos);
	}

	bool Frame::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		bool res = ActionTarget::processEvent(event);
		if (not res)
			res = Container::processEvent(event, parent_pos);
		return res;
	}

	void Frame::processEvents(const sf::Vector2f& parent_pos)
	{
		ActiontTarget::processEvents();
		Container::processEvents(parent_pos);

		sf::Event event;

		while (window_.pollEvent(event))
			Container::processEvent(event, parent_pos);
	}
}