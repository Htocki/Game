#include "Layout.hpp"
#include <stdexcept>



namespace gui
{
	Layout::Layout(Widget* parent)
		: Widget(parent)
		, space_(5)
	{}

	Layout::~Layout()
	{}

	void Layout::setSpace(float pixels)
	{
		if (pixels >= 0)
		{
			space_ = pixels;
			updateShape();
		}
		else
			throw std::invalid_argument("pixel value must be >= 0");
	}
}