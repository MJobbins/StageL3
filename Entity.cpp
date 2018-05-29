#include "Entity.h"
#include "Point3d.h"

Point3d Entity::getPosition() const{
	// TODO - implement Entity::getPosition
	throw "Not yet implemented";
}

void Entity::setPosition(Point3d m_position) {
	// TODO - implement Entity::setPosition
	throw "Not yet implemented";
}

Point3d Entity::getRotation() const{
	// TODO - implement Entity::getRotation
	throw "Not yet implemented";
}

void Entity::setRotation() {
	// TODO - implement Entity::setRotation
	throw "Not yet implemented";
}

Point3d Entity::getSize() const{
	// TODO - implement Entity::getSize
	throw "Not yet implemented";
}

void Entity::setSize() {
	// TODO - implement Entity::setSize
	throw "Not yet implemented";
}

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

bool Entity::intersects(Vector3d vect) const{
	// TODO - implement Entity::intersects
	throw "Not yet implemented";
}

Point3d Entity::intersectionPoint(Vector3d vect) const
{
	return Point3d();
}

Color Entity::getColor(Point3d p) const
{
	return m_visual.getColor(p);
}
