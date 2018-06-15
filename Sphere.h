#ifndef SPHERE_H
#define SPHERE_H

#include "Geometry.h"

class Sphere : public Geometry {

public :

    static const float DEFAULT_RAYON;

    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

    Sphere();
    Sphere(Sphere const& source);
    explicit Sphere(float rayon);

    ~Sphere();


    //Assignement operators
    //=====================

    Sphere& operator=(Sphere const& source);


    //Comparison operators
    //====================

    friend bool operator==(Sphere const& lhs, Sphere const& rhs);
    friend  bool operator!=(Sphere const& lhs, Sphere const& rhs);


    //Setters and Getters
    //===================

    void getRayon();

    void setRayon();


    //Other functions
    //===============

    bool intersects(Ray const& ray, Point3d const& position, Hit &hit) const;

private :

    /*****************
    **    ATTRIBUTS
    ******************/

	float m_rayon;

};

#endif
