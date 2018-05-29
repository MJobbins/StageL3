#ifndef ENTITY_H
#define ENTITY_H

#include "Point3d.h"
#include "Vector3d.h"

class Entity {

private:
	Point3d m_position;
	Point3d m_rotation;
	Point3d m_size;

public:
	Point3d getPosition();

	void setPosition(Point3d m_position);

	Point3d getRotation();

	void setRotation();

	Point3d getSize();

	void setSize();

	void translate();

	void rotate();

	void scale();

	bool isInEntity(Point3d p);

	bool intersects(Vector3d vect);
};

#endif
