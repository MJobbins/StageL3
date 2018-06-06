#include "Ray.h"
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"

Point3d Ray::getOrigin() const{
	return m_origin;
}

Vector3d Ray::getDirection() const{
    return  m_direction;
}

Color Ray::getColor() const{
	return m_energy;
}

Ray::Ray()
{}

Ray::Ray(Ray const &source)
{

}

Ray::Ray(Point3d origin, Vector3d direction, Color energy) :
m_origin(origin),
m_direction(direction),
m_energy(energy)
{}

Ray::~Ray()
{

}

Ray &Ray::operator=(Ray const &source)
{
	return *this;
}

void Ray::setOrigin(Point3d const &source)
{
    m_origin = source;
}

void Ray::setDirection(Vector3d const &source)
{
    m_direction = source;
}

void Ray::setColor(Color const &source)
{
    m_energy = source;
}
