#include "Hit.h"
//#include "Entity.h"
//#include "Vector3d.h"
//#include "Ray.h"
#include <iostream>

//Constructors & destructors
//==========================

Hit::Hit() :
m_entity(nullptr),
m_ptIntersection(Point3d::ZERO),
m_normal(Vector3d::ZERO),
m_u(0.0f),
m_v(0.0f),
m_distance(0.0f),
m_hit(false)
{}

Hit::Hit(Hit const &source) :
m_entity(source.m_entity),
m_ptIntersection(source.m_ptIntersection),
m_normal(source.m_normal),
m_u(source.m_u),
m_v(source.m_v),
m_distance(source.m_distance),
m_hit(source.m_hit)
{}

Hit::Hit(Entity entity, Point3d point, Vector3d normal, float u, float v, float distance, bool hit) :
m_entity(&entity),
m_ptIntersection(point),
m_normal(normal),
m_u(u),
m_v(v),
m_distance(distance),
m_hit(hit)
{}

Hit::~Hit()
{}


//Assignement operators
//=====================

Hit &Hit::operator=(Hit const &rhs)
{
	m_entity = rhs.m_entity;
	m_ptIntersection = rhs.m_ptIntersection;
	m_normal = rhs.m_normal;
	m_u = rhs.m_u;
	m_v = rhs.m_v;
	m_distance = rhs.m_distance;
	m_hit = rhs.m_hit;

	return(*this);
}


//Comparison operators
//====================

bool operator==(Hit const &lhs, Hit const &rhs)
{
	return (*(lhs.m_entity) == *(rhs.m_entity)) &&
            (lhs.m_ptIntersection == rhs.m_ptIntersection) &&
            (lhs.m_normal == rhs.m_normal) &&
            (lhs.m_u == rhs.m_u) &&
            (lhs.m_v == rhs.m_v) &&
            (lhs.m_distance == rhs.m_distance) &&
            (lhs.m_hit == rhs.m_hit);
}


//Getters et setters
//==================

Entity Hit::getEntity() const
{
	return *m_entity;
}

void Hit::setEntity(Entity& entity)
{
    m_entity = &entity;
}

Point3d Hit::getPtIntersection() const
{
	return m_ptIntersection;
}

void Hit::setPtIntersection(Point3d const &point)
{
    m_ptIntersection = point;
}

Vector3d Hit::getNormal() const
{
	return m_normal;
}

void Hit::setNormal(Vector3d const &normal)
{
    m_normal = normal;
}

float Hit::getU() const
{
	return m_u;
}

void Hit::setU(float u)
{
    m_u = u;
}

float Hit::getV() const
{
	return m_v;
}

void Hit::setV(float v)
{
    m_v = v;
}

float Hit::getDistance() const
{
	return m_distance;
}

void Hit::setDistance(float distance)
{
    m_distance = distance;
}

bool Hit::getHit() const
{
    return m_hit;
}

void Hit::setHit(bool hit)
{
    m_hit = hit;
}


Ray Hit::makeRay() {
	// TODO - implement Hit::makeRay
	throw "Not yet implemented";
}
