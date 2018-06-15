#ifndef HIT_H
#define HIT_H

#include "Entity.h"
#include "Vector3d.h"
#include "Ray.h"

class Hit {

private:
	Entity *m_entity;
	Point3d m_ptIntersection;
	Vector3d m_normal;
	float m_u;
	float m_v;
	float m_distance;
	bool m_hit;

public:

    /*****************
	**    METHODES
	******************/

    //Constructors & destructors
    //==========================

    Hit();
    Hit(Hit const& source);
    Hit(Entity entity,
        Point3d point,
        Vector3d normal,
        float u,
        float v,
        float distance,
        bool hit);
    ~Hit();

    //Assignement operators
    //=====================

    Hit& operator=(Hit const& rhs);

    //Comparison operators
    //====================

    friend bool operator==(Hit const& lhs, Hit const& rhs);

    //Getters et setters
    //==================

    Entity getEntity() const;
    void setEntity(Entity& entity);

	Point3d getPtIntersection() const;
	void setPtIntersection(Point3d const& point);

	Vector3d getNormal() const;
	void setNormal(Vector3d const& normal);

	float getU() const;
	void setU(float u);

	float getV() const;
	void setV(float v);

	float getDistance() const;
	void setDistance(float distance);

	bool getHit() const;
	void setHit(bool hit);

	Ray makeRay();
};

#endif
