#ifndef RAY_H
#define RAY_H

#include <vector>
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "SpotLight.h"

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
