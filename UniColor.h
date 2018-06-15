#ifndef UNICOLOR_H
#define UNICOLOR_H

#include "Optic.h"
#include "Color.h"

class UniColor : public Optic {

public:

    UniColor();
    UniColor(Color const& c);



	Color getColor();

	void setColor();

	Color getColor(float u, float v) const;

private:

	Color m_color;
};

#endif
