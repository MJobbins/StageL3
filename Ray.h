#ifndef RAY_H
#define RAY_H

#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"

class Ray {

private:
	Point3d m_origin;
	Vector3d m_direction;
	Color m_energy;

public:
	Point3d getOrigin();

	Vector3d getDirection();

	Color getColor();
};

#endif
