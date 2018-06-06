#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Ray.h"

class Geometry {


public:

	virtual ~Geometry() = 0;

	virtual bool intersects(Ray const& ray, Point3d const& position) const = 0;
	virtual Point3d intersectionPoint(Ray const& ray, Point3d const& position) const = 0;


};

#endif