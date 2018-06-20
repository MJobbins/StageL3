#ifndef OPTIC_H
#define OPTIC_H

#include "Color.h"
#include "Point3d.h"

class Optic {

private:
	float m_mirror;
	Color m_specularColor;

public:

	Optic();

	virtual ~Optic();

	float getMirror() const;

	void setMirror(float m);

	Color getSpecularColor() const;

	void setSpecularColor(Color c);

	Color getColorMirrror(int Point3d_p);

	float getDiffuse();

	float getTransparency();

	void getColorDiffuse();

	virtual Color getColor(float u, float v) const = 0;
};

#endif
