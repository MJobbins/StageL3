#ifndef RAY_H
#define RAY_H

#include <vector>
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "SpotLight.h"

//#include "Hit.h"
class Hit;

class Entity;

class Ray {



public:

    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

	Ray();
	Ray(Ray const& source);
	Ray(Point3d origin, Vector3d direction, Color energy);
	~Ray();


    //Assignement operators
    //=====================

    Ray& operator=(Ray const& source);

    //Setters and Getters
    //===================

	Point3d getOrigin() const;
	void setOrigin(Point3d const& source);

	Vector3d getDirection() const;
	void setDirection(Vector3d const& source);

	Color getColor() const;
	void setColor(Color const& source);

	Color difuseColor(const std::vector<Entity*>* scene, const std::vector<SpotLight*>* lights, Hit closestHit, float mirror);
    Color specularColor(const std::vector<Entity*>* scene ,const std::vector<SpotLight*>* lights, Hit closestHit);

	Hit checkHit(const std::vector<Entity*> *scene);
	Color traceRay(const std::vector<Entity*>* scene, const std::vector<SpotLight*> *lights);

private:

    /*****************
    **    ATTRIBUTS
    ******************/

    Point3d m_origin;
    Vector3d m_direction;
    Color m_energy;
};

#endif
