#ifndef UNICOLOR_H
#define UNICOLOR_H

#include "Optic.h"
#include "Color.h"

class UniColor : Optic {

public:
	Color m_color;

	Color getColor();

	void setColor();
};

#endif
