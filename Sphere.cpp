#include <cmath>
#include <iostream>
#include "Sphere.h"
#include "Hit.h"

const float Sphere::DEFAULT_RAYON (0.0f);
const float  PI_F=3.14159265358979f;


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

bool Sphere::intersects(Ray const& ray, Point3d const& position, Hit &hit) const
{
	Vector3d d = ray.getDirection();
	Vector3d OC = Vector3d(ray.getOrigin(), position);
	float k = produitScalaire(d , OC);
	if(k < 0) {
	    hit.setHit(false);
	    return false;
	}
	float h2 = produitScalaire(OC, OC) - k*k;

    float delta = sqrt(m_rayon*m_rayon - h2);

    Vector3d OP1 = (k-delta) * d;

    hit.setPtIntersection(Point3d( ray.getOrigin().getX() + OP1.getX(),
                                   ray.getOrigin().getY() + OP1.getY(),
                                   ray.getOrigin().getZ() + OP1.getZ()
    ));

    hit.setHit(h2 <= m_rayon*m_rayon);

    if(hit.getHit()) {
        hit.setDistance(ray.getOrigin().distance(hit.getPtIntersection())); // Position = sphere pas camera A CHANGER
        Vector3d normal(Vector3d(position, hit.getPtIntersection()));
        normal.normalize();
        hit.setNormal(normal);


        // CALCUL DE U ET V, A PLACER DANS UNE AUTRE FONCTION
        //Vector3d Vn(0, 0, m_rayon);
        //Vector3d Ve(0, m_rayon, 0);
        //Vector3d Vp(position, hit.getPtIntersection());
        //Vp.normalize();

        //TEST FOR U AND V 2nd
        Vector3d Vp(hit.getPtIntersection(),position );
        Vp.normalize();

    /*
        float phi = acosf(-(Vn ^ Vp));
        hit.setV(phi / PI_F);
        //std::cout<< "phi : " << phi/PI_F << std::endl;

        float theta = ((acosf((Vp ^ Ve) / sinf(phi))) / (2.0f * PI_F));

        //std::cout << "theta : " << theta << std::endl;

        if (((Vn * Ve) ^ Vp) > 0.0f)
            hit.setU(theta);
        else
            hit.setU(1 - theta);

*/
        //V2 TRY
        float u = 0.5f + ((atan2f(Vp.getY(), Vp.getX()))/ (2.0f * PI_F));
        //float v = 0.5f - (asinf(Vp.getZ())/ PI_F);
        float v = -Vp.getZ() / 2.0f + 0.5f;

        /*std::cout << "uv (" << u << ", " << v << ") p(" << hit.getPtIntersection().getX()
                  << ", " << hit.getPtIntersection().getY() << ", " << hit.getPtIntersection().getZ()
                  << ") vp(" << Vp.getX() << ", " << Vp.getY() << ", " << Vp.getZ() << ")" << std::endl;
        */
        //V3 TRY
       /* float tempV = acosf(Vp.getZ());
        float tempU = atan2f(Vp.getY(), Vp.getX());

        if(tempU < 0)
            tempU += (2*PI_F);

        float u = tempU / (2*PI_F);
        float v = tempV/PI_F;
    */
        hit.setU(u);
        hit.setV(v);
    }

    return hit.getHit();
}

