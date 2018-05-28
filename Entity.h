#ifndef ENTITY_H
#define ENTITY_H

#include "Point3d.h"

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

	bool isInEntity(int p_Point3d);

	bool intersects(int Vector3d_vect);
};

#endif
