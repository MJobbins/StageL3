#include <iostream>
#include "Entity.h"
#include "Point3d.h"
#include "Hit.h"

//Constructors & destructors
//==========================


Entity::Entity() :
m_position(Point3d::ZERO),
m_rotation(Point3d::ZERO),
m_size(1.0f),
m_shape(nullptr),
m_visual(nullptr)
{}

Entity::Entity(Entity const &source) :
m_position(source.m_position),
m_rotation(source.m_rotation),
m_size(source.m_size),
m_shape(source.m_shape),
m_visual(source.m_visual)
{

}

Entity::Entity(Geometry &shape, Optic &view) :
m_position(Point3d::ZERO),
m_rotation(Point3d::ZERO),
m_size(1.0f),
m_shape(&shape),
m_visual(&view)
{}

Entity::Entity(Geometry &shape, Optic &view, Point3d const& position, Point3d const& rotation, float scale) :
m_position(position),
m_rotation(rotation),
m_size(scale),
m_shape(&shape),
m_visual(&view)
{}

Entity::~Entity()
{}

//Assignement operators
//=====================


Entity& Entity::operator=(Entity const &source)
{
    m_position = source.m_position;
    m_rotation = source.m_rotation;
    m_size = source.m_size;
    m_shape = source.m_shape;
    m_visual = source.m_visual;

    return(*this);
}

//Comparison operators
//====================


bool operator==(Entity const &lhs, Entity const &rhs)
{
    return (lhs.m_position == rhs.m_position) &&
           (lhs.m_rotation == rhs.m_rotation) &&
           (lhs.m_size == rhs.m_size) &&
           (lhs.m_shape == rhs.m_shape) &&
           (lhs.m_visual == rhs.m_visual);
}

bool operator!=(Entity const &lhs, Entity const &rhs)
{
    return !(lhs == rhs);
}

//Setters and Getters
//===================


Point3d Entity::getPosition() const{
	return m_position;
}

void Entity::setPosition(Point3d position) {
	m_position = position;
}

Point3d Entity::getRotation() const{
	return m_rotation;
}

void Entity::setRotation(Point3d rotation) {
	m_rotation = rotation;
}

float Entity::getSize() const{
	return m_size;
}

void Entity::setSize(float size) {
	m_size = size;
}

//Other functions
//===============


void Entity::translate() {
	// TODO - implement Entity::translate
	throw "Not yet implemented";
}

void Entity::rotate() {
	// TODO - implement Entity::rotate
	throw "Not yet implemented";
}

void Entity::scale() {
	// TODO - implement Entity::scale
	throw "Not yet implemented";
}

bool Entity::isInEntity(Point3d p) const{
	// TODO - implement Entity::isInEntity
	throw "Not yet implemented";
}

bool Entity::intersects(Ray const& ray, Hit &hit) const{
	return this->m_shape->intersects(ray, m_position, hit);
}


Color Entity::getColor(float u, float v, Hit &hit) const
{
	Color colorOnPoint(m_visual->getColor(u, v));
	return colorOnPoint;
}

float Entity::getMirror() const
{
    return m_visual->getMirror();
}

float Entity::setMirrror(float m)
{
    m_visual->setMirror(m);
}




