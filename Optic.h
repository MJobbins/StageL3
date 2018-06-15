#ifndef OPTIC_H
#define OPTIC_H

#include "Color.h"
#include "Point3d.h"

class Optic {

private:
	float m_mirror;

public:
	float getMirror();

	void setMirror();

	Color getColorMirrror(int Point3d_p);

	float getDiffuse();

	float getTransparency();

	void getColorDiffuse();

	virtual Color getColor(float u, float v) const = 0 ;
};

#endif
