#ifndef HIT_H
#define HIT_H

#include "Entity.h"
#include "Vector3d.h"
#include "Ray.h"

class Hit {

private:
	Entity m_entity;
	Point3d m_ptIntersection;
	Vector3d m_normal;
	float m_u;
	float m_v;
	float m_distance;

public:
	Entity getEntity();

	Point3d getPtIntersection();

	Vector3d getNormal();

	Ray makeRay();
};

#endif
