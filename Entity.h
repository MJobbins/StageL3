#ifndef ENTITY_H
#define ENTITY_H

#include "Point3d.h"
#include "Vector3d.h"
#include "Geometry.h"
#include "Optic.h"

class Entity {

private:
	Point3d m_position;
	Point3d m_rotation;
	Point3d m_size;

	Geometry m_shape;
	Optic m_visual;

public:
	Point3d getPosition() const;

	void setPosition(Point3d m_position);

	Point3d getRotation() const;

	void setRotation();

	Point3d getSize() const;

	void setSize();

	void translate();

	void rotate();

	void scale();

	bool isInEntity(Point3d p) const;

	bool intersects(Vector3d vect) const;

	Point3d intersectionPoint(Vector3d vect) const;

	Color getColor(Point3d p) const;
};

#endif
