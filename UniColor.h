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

	Color getColor(Point3d p) const;

private:

	Color m_color;
};

#endif
