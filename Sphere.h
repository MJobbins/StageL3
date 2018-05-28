#ifndef SPHERE_H
#define SPHERE_H

#include "Geometry.h"

class Sphere : public Geometry {

public:
	float m_rayon;

	void getRayon();

	void setRayon();
};

#endif
