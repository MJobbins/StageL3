#include <mach/mig_errors.h>
#include <cmath>
#include "Sphere.h"

const float Sphere::DEFAULT_RAYON (0.0f);


//Constructors & destructors
//==========================

Sphere::Sphere() :
m_rayon(DEFAULT_RAYON)
{}

Sphere::Sphere(Sphere const &source) :
m_rayon(source.m_rayon)
{}

Sphere::Sphere(float rayon) :
m_rayon(rayon)

{}

Sphere::~Sphere()
{}


//Assignement operators
//=====================

Sphere &Sphere::operator=(Sphere const &source)
{
    return *this;
}


//Comparison operators
//====================

bool operator==(Sphere const &lhs, Sphere const &rhs)
{
    return false;
}

bool operator!=(Sphere const &lhs, Sphere const &rhs)
{
    return false;
}


//Setters and Getters
//===================

void Sphere::getRayon() {
	// TODO - implement Sphere::getRayon
	throw "Not yet implemented";
}

void Sphere::setRayon() {
	// TODO - implement Sphere::setRayon
	throw "Not yet implemented";
}


//Other functions
//===============

bool Sphere::intersects(Ray const& ray, Point3d const& position) const
{
	Vector3d d = ray.getDirection();
	Vector3d OC = Vector3d(ray.getOrigin(), position);
	float k = produitScalaire(d , OC);
	if(k < 0) {
	    return false;
	}
	float h2 = produitScalaire(OC, OC) - k*k;

	return h2 <= m_rayon*m_rayon;
}

Point3d Sphere::intersectionPoint(Ray const& ray, Point3d const& position) const
{
    Vector3d d = ray.getDirection();
    Vector3d OC = Vector3d(ray.getOrigin(), position);
    float k = produitScalaire(d , OC);
    float h2 = produitScalaire(OC, OC) - k*k;

    float delta = sqrt(m_rayon*m_rayon - h2);

    Vector3d OP1 = (k-delta) * d;

    return Point3d( ray.getOrigin().getX() + OP1.getX(),
                    ray.getOrigin().getY() + OP1.getY(),
                    ray.getOrigin().getZ() + OP1.getZ()
                    );
}

