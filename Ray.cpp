#include <iostream>
#include "Ray.h"
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "Hit.h"
#include "Entity.h"
#include "SpotLight.h"

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

Color Ray::traceRay(const std::vector<Entity*> *scene, const std::vector<SpotLight*> *lights)
{
    Hit closestHit; // Ce sera notre hit final.

    for (const auto &i : *scene) {
        Hit currentHit;
        currentHit.setEntity(*i);
        currentHit.setOriginalRay(m_direction);

        if (i->intersects(*this, currentHit)) {
            if (!closestHit.getHit()) {
                //std::cout << "premier" << std::endl;
                closestHit = currentHit;
            } else {
                if (closestHit.getDistance() > currentHit.getDistance())
                    closestHit = currentHit;
            }
        }
    }

    //Should seperate in a second function here.

    if(closestHit.getHit()) {
        std::cout << "hit ? : " << closestHit.getHit() << std::endl;
        std::cout << " Entity touched : " << closestHit.getEntity().getPosition().getX() << std::endl;

        float mirror = closestHit.getEntity().getMirror();
        std::cout << "mirror : " <<  mirror << std::endl;

        //return closestHit.getColor();
        if (mirror > 0) {
            //La couleur non réfléchie.
            Color col1 = closestHit.getColor() * (1 - mirror);
            col1 *= ;



            //La couleur réflechie.
            float c1 = -(closestHit.getNormal() ^ closestHit.getOriginalRay());
            Vector3d refracted = closestHit.getOriginalRay() + (2 * closestHit.getNormal() * c1);


            Ray refractedRay(closestHit.getPtIntersection(), refracted, Color(1.0f));

            Color col2 = mirror * refractedRay.traceRay(scene, lights);


            return col1+col2;


        }
        return closestHit.getColor();
    }
    else {
        return Color::BLACK; //Pour le moment noir, lorsqu'on auras de
        //La lumière il faudras mettre la couleur de la lumière
    }
}
