#include "UniColor.h"
#include "Color.h"

Color UniColor::getColor() {
	// TODO - implement UniColor::getColor
	throw "Not yet implemented";
}

void UniColor::setColor() {
	// TODO - implement UniColor::setColor
	throw "Not yet implemented";
}

Color UniColor::getColor(Point3d p) const
{
    return m_color;
}

UniColor::UniColor() :
m_color(Color::WHITE)
{}

UniColor::UniColor(Color const &c) :
m_color(c)
{}
