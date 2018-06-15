#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Point3d.h"
#include "Ray.h"
class Hit;

class Geometry {


public:

	virtual ~Geometry() = 0;

	virtual bool intersects(Ray const& ray, Point3d const& position, Hit &hit) const = 0;


};

#endif