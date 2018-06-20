#include <iostream>
#include <sys/param.h>
#include <math.h>
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

Hit Ray::checkHit(const std::vector<Entity*> *scene)
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

    return closestHit;
}

Color Ray::difuseColor(const std::vector<Entity*>* scene ,const std::vector<SpotLight*>* lights, Hit closestHit, float mirror)
{
    Color col1 = closestHit.getColor();
    Color difuseColor(0.0);
    for(const auto &i : *lights)
    {
        Vector3d dir(i->getPosition(), closestHit.getPtIntersection());
        dir.normalize();

        float distLE = i->getPosition().distance(closestHit.getPtIntersection());

        Ray lightRay(i->getPosition(), dir, Color::WHITE);
        Hit closestLightHit = lightRay.checkHit(scene);


        //On ajout une petit floatp pour le manque de précision des calculs.
        if (closestLightHit.getHit() && (distLE <= closestLightHit.getDistance()+0.001f) )
        {
            float cosB = (closestHit.getNormal()^(-dir))/ closestHit.getNormal().length() * (-dir).length();
            difuseColor += i->getColor() * cosB;
        }
    }

    col1 *= difuseColor + 0.05; //0.05 = ambiant color.
    col1 *= (1-mirror);
    return col1;
}

Color Ray::specularColor(const std::vector<Entity*>* scene ,const std::vector<SpotLight*>* lights, Hit closestHit)
{
    Color specColor = closestHit.getEntity().getSpecularColor();

    float specMulti = 0;

    for(const auto &i : *lights)
    {
        Vector3d dir(i->getPosition(), closestHit.getPtIntersection());
        dir.normalize();

        float distLE = i->getPosition().distance(closestHit.getPtIntersection());

        Ray lightRay(i->getPosition(), dir, Color::WHITE);
        Hit closestLightHit = lightRay.checkHit(scene);


        //On ajout une petit floatp pour le manque de précision des calculs.
        if (closestLightHit.getHit() && (distLE <= closestLightHit.getDistance()+0.001f) )
        {
            float cosA= -((-dir)^closestHit.getNormal())*2.0f;

            Vector3d tmpNormal(closestHit.getNormal() * cosA);
            //tmpNormal.normalize();
            Vector3d reflectVector = tmpNormal + (-dir);
            reflectVector.normalize();

            specMulti = MAX(-(reflectVector^(-dir)), 0);
            specMulti = powf(specMulti, 5);
        }
    }
    specColor *= specMulti;
    return specColor;
}


Color Ray::traceRay(const std::vector<Entity*> *scene, const std::vector<SpotLight*> *lights)
{

    Hit closestHit = checkHit(scene);

    if(closestHit.getHit()) {

        float mirror = closestHit.getEntity().getMirror();

        Color mirrorColor(0.0);

        if (mirror > 0) {

            /*
             * AJOUTER COULEUR AMBIANTE
             */

            //La couleur réflechie.
            float c1 = -(closestHit.getNormal() ^ closestHit.getOriginalRay());
            Vector3d refracted = closestHit.getOriginalRay() + (2 * closestHit.getNormal() * c1);

            Ray refractedRay(closestHit.getPtIntersection(), refracted, Color(1.0f));

            mirrorColor = mirror * refractedRay.traceRay(scene, lights);

        }
        //La couleur non réflechie
        Color difColor = difuseColor(scene, lights, closestHit, mirror);

        //La couleur birllante (specular)
        Color specColor = specularColor(scene, lights, closestHit);


        Color result(difColor + specColor + mirrorColor);
        result.clamp();
        return result;
    }
    else {
        return Color::BLACK; //Pour le moment noir, lorsqu'on auras de
        //La lumière il faudras mettre la couleur de la lumière
    }
}