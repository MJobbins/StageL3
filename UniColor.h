#ifndef UNICOLOR_H
#define UNICOLOR_H

#include "Optic.h"
#include "Color.h"

class UniColor : public Optic {

public:
	Color m_color;

	Color getColor();

	void setColor();

	Color getColor(Point3d p) const;
};

#endif
